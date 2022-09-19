#include<stdio.h>
#include<signal.h>
#include <sys/types.h>
#include<unistd.h>


int main()
{

        kill(7281,2);
        kill(7281,4);
        kill(7281,8);
        kill(7281,11);
        kill(7281,15);
        kill(7281,17);
  
}
