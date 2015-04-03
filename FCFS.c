#include<stdio.h>
int main()
{
	int proc,burst_t[10],wait_t[10],turna_t[10];
	printf("Enter number of processes:");
	scanf("%d",&proc);
	printf("\nEnter Process Burst Time:");
	for(int i=0;i<proc;i++)
	{
		printf("P[%d]:",i+1);
		scanf("%d",&burst_t[i]);
	}
wait_t[0]=0;    
for(int i=1;i<n;i++)
{
	wait_t[i]=0;
	for(int j=0;j<i;j++)
	{
		wait_t[i]=wait_t[i]+burst_t[j];
	}

}
//printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

for(int i=0;i<proc;i++)
{
	turna_t[i]=burst_t[i]+wait_t[i];

printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,burst_t[i],wait_t[i],turna_t[i]);

}

return 0;

}
