#include<stdio.h>
void main()
{
	int i,n;
	float avgwt=0;
	printf("enter the no of processes\n");
	scanf("%d",&n);
	int at[n],wt[n],bt[n],tt[n],tat[n];
	printf("enter the arrival time of processes\n");
	for(i=0;i<n;i++)
	scanf("%d",&at[i]);
	printf("enter the burst time of processes\n");
	for(i=0;i<n;i++)
	scanf("%d",&bt[i]);
	tt[0]=bt[0];	
	for(i=1;i<n;i++)
	{
		tt[i]=tt[i-1]+bt[i];
	}
	printf("total time for processes:\n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",tt[i]);
	}
	for(i=0;i<n;i++)
	{
		tat[i]=tt[i]-at[i];
	}
	printf("turnaround time:\n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",tat[i]);
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	printf("waiting time of process\n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",wt[i]);
	}
	for(i=0;i<n;i++)
	{
		avgwt=avgwt+wt[i];
	}
	avgwt=avgwt/n;
	printf("average waiting time: %f \n",avgwt);
}
