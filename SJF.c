#include<stdio.h>
int main()
{
	int i,j,proc,p[10],burst_t[10],wait_t[10],turna_t[10],temp,temp1;
	printf("Enter number of processes:");
	scanf("%d",&proc);
	printf("\nEnter Process Burst Time:");
	for(i=0;i<proc;i++)
	{
		printf("P[%d]:",i+1);
		scanf("%d",&burst_t[i]);
		p[i]=i;
	}
wait_t[0]=0;    
for(i=1;i<proc;i++)
{
	
	for(j=i;j<proc;j++)
	{
		if(burst_t[i]>burst_t[j])
		{
			temp=burst_t[i];
			temp1=p[i];
			burst_t[i]=burst_t[j];
			p[i]=p[j];
			burst_t[j]=temp;
			p[j]=temp1;
		}
			
		
	}

}

for(i=0;i<proc;i++)
{
	wait_t[i+1]=wait_t[i]+burst_t[i];
}
//printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

for(i=0;i<proc;i++)
{
	turna_t[i]=burst_t[i]+wait_t[i];

printf("\nP[%d]\t\t%d\t\t%d\t\t%d\n",p[i],burst_t[i],wait_t[i],turna_t[i]);

}

return 0;

}
