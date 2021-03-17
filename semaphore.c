#include<stdio.h>
#include<unistd.h>
int lock;
int acquire()
{
	sleep(3);
	return release();
}
int release()
{
	return 1;
}

int main()
{
	int i,n,p,k=0;
	printf("ENTER NO OF PROCESSES\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		lock=0;
		while(lock==0)
		{
			printf("PROCESS P%d IN CRITICAL SECTION\n",i);
			lock=acquire();
			printf("PROCESS P%d LEAVING CRITICAL SECTION\n",i);
		}
		
		k=0;
		printf("PROCESS THAT ARE WAITING\n");
		while((k+i+1)<n)
		{
			printf("P%d\n",i+k+1);
			k++;
		}
		
	}
}
