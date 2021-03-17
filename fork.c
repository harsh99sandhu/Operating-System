#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{	
	int a=fork();
	if(a==0)
	{printf("child %d \n",getpid());}
	else if(a>0)
	{
	printf("parent %d \n",getpid());
	}
	else if(a<0)
	{
		printf("unsuccesfull %d \n",getpid());
	}
	return 0;
}

