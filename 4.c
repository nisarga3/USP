#include<stdio.h>
#include<setjmp.h>

jmp_buf buf,buf2;

void lap()
{
	printf("Weclome to the lap function\n");
	longjmp(buf,1);
}


void lap2()
{
	printf("Weclome to the lap2 function\n");
	longjmp(buf,2);
}
 void main()
{
	printf("In the main function\n");
	if(setjmp(buf)==1)
	{
		printf("back to the main frm lap\n");
		if(setjmp(buf)==2)
		{
			printf("back to the main frm lap2\n");
			
		}
		else
		{
			printf("Goin to lap2 function\n");
			lap2();	
		}	
	}
	else
	{
		printf("Goin to lap function\n");
		lap();	
		printf("This statement will not be printed\n");
	}		
	

}
