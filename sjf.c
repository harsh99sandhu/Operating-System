#include<stdio.h>
void main()
{
	int i,j,temp,at[100],wt[100],bt[100],tt[100],tat[100],n;
	float avgwt=0;
	printf("enter the no of processes\n");
	scanf("%d",&n);
	printf("enter the arrival time of processes\n");
	for(i=0;i<n;i++)
	scanf("%d",&at[i]);
	printf("enter the burst time of processes\n");
	for(i=0;i<n;i++)
	scanf("%d",&bt[i]);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(bt[i]>bt[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
			}
		}
	}
	printf("sorted processes according to their burst time:\n");
	for(i=0;i<n;i++)
	{
		printf("Burst time P[%d] = %d \n",i,bt[i]);
	}
	tt[0]=bt[0];	
	for(i=1;i<n;i++)
	{
		tt[i]=tt[i-1]+bt[i];
	}
	printf("total time for processes:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",tt[i]);
	}
	for(i=0;i<n;i++)
	{
		tat[i]=tt[i]-at[i];
	}
	printf("turnaround time:\n");
	for(i=0;i<n;i++)
	{
		printf("%d \n ",tat[i]);
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	printf("waiting time of process\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",wt[i]);
	}
	for(i=0;i<n;i++)
	{
		avgwt=avgwt+wt[i];
	}
	avgwt=avgwt/n;
	printf("average waiting time:%f\n",avgwt);
}
