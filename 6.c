#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handle_sigint(int sig)
{
    switch(sig)
    {
        case SIGINT:
              printf("Caught signal %d -SIGINT\n", sig);
              break;
        case SIGFPE:
              printf("Caught signal %d -SIGFPE\n", sig);  
                break; 
         case SIGSEGV:
              printf("Caught signal %d -SIGSEGV\n", sig);
              break;
        case SIGCHLD:
              printf("Caught signal %d -SIGCHLD\n", sig);  
                break;
        case SIGTERM:
              printf("Caught signal %d -SIGTERM\n", sig); 
                break;    
        case SIGILL:
              printf("Caught signal %d -SIGILL\n", sig); 
                break;
        default:
            printf("Not listed-Some signal caught\n");     
            break;
    }
  
}
  
int main()
{
    signal(SIGINT, handle_sigint);
    signal(SIGFPE, handle_sigint);
    signal(SIGSEGV, handle_sigint);
    signal(SIGCHLD, handle_sigint);
    signal(SIGILL, handle_sigint);
    signal(SIGTERM, handle_sigint);
    while (1);
    return 0;
}
