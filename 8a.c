#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	int p1[2], p2[2];
	pipe(p1); pipe(p2);
	int rv = fork();
	if(rv==0)
	{
		char buf[100];
		printf("This is Child \nEnter the data to be to sent to Parent\n");
		scanf("%[^\n]s",buf);
		int nb=write(p1[1],buf,sizeof(buf));
		if(nb)
			printf("Data sent successfully\n");
	}
	else
	{
		char buf[100];
		fd_set rd_set;
		fd_set wr_set;
		struct timeval tv;
		FD_ZERO(&rd_set);		
		FD_ZERO(&wr_set);
		FD_SET(p1[0],&rd_set);
		FD_SET(p1[1],&wr_set);
		tv.tv_sec = 10;
		tv.tv_usec = 0;
		int  r= select(p1[0]+1,&rd_set,NULL,NULL,&tv);
		if(r == -1)
			printf("Error in Select");
		else if(r)
		{
			if(FD_ISSET(p1[0],&rd_set))
            {
            	read(p1[0], buf, 10);
            	printf("Message recieved from 1!!\n");
                        
            }
            else if(FD_ISSET(p2[0],&rd_set))
            {
            	read(p2[0], buf, 10);
     	        printf("Message recieved from 2!!\n");
            }
			printf("This is Parent\nThe data sent by child is\n");
            printf("%s\n", buf);
		}
	
		else
		printf("No Data written by the Child in 10 seconds ,Exiting...\n");
	}
}
