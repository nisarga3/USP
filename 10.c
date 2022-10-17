#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<stdlib.h>

int key,shm_id,sem_id;
char* shm_ptr;
int main()
{
    key = ftok("home/nisarga/Desktop/USP/lab/practise",6);
    shm_id = shmget(key,10,IPC_CREAT|0666);
    shm_ptr = (char*)shmat(shm_id,NULL,0);
    sem_id = semget(key,1,IPC_CREAT|0666);
     //printf("%d\n",sem_id);
    semctl(sem_id,0,SETVAL,1);

    int v = fork();
    if(v==0)
    {
        int chk=0;
        while(!chk)
        {
            int x = semctl(sem_id,0,GETVAL);
            printf("Child: Current semaphore value -> %d\n",x);
            if(x==1)
            {
                chk=1;
                int x  = semctl(sem_id,0,SETVAL,0);
                printf("The value of the shared memory is %s\n",shm_ptr);
                int v  = semctl(sem_id,0,SETVAL,1);
                break;
            }
            else
            {
                printf("Semaphore not available!\n");
                sleep(5);
            }
        }
        printf("Child exiting\n");
    }
    else
    {
        int x = semctl(sem_id,0,GETVAL);
        printf("Parent: Current semaphore value -> %d\n",x);
        if(x==1)
        {
            semctl(sem_id,0,SETVAL,0);
            printf("Parent accessed semaphore!\n");

            // char num = (char)malloc(sizeof(char)*10);
            char num[10] = "0123456789";

            for(int i=0;i<10;i++)
            {
                *(shm_ptr+i) = num[i];
                if(i==5)
                {
                    printf("Parent printed 5 values into the shared memory!\nGoing to sleep now..");
                    sleep(1);
                    printf("Parent wakes up!\n");
                }
            }
        semctl(sem_id,0,SETVAL,1);
        printf("Finally parent printed 10 nums into shared\nParent exiting...\n");
        }
    }
}
