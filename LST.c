#include<stdio.h>


void main()
{

 int proc,wait_prev,temp;
 int i,k,l,m;
 printf("\nEnter the no of processes:");
 scanf("%d",&proc);
 
 int exec[proc],start[proc],deadline[proc], flag[proc];
 for(i=0;i<proc;i++)
 {
	flag[proc] = 0;
 }
 wait_prev = 0;
  
 
 
 for(i=0;i<proc;i++)
 {
 	printf("\nEnter absolute start time, exec time and absolute deadline for process %d:",i+1);
 	scanf("%d %d %d", &start[i], &exec[i], &deadline[i]);
 }
	
 int time_quatum      = 0;
 int end_false        = 1;
 int smallest_slack = 10000;
 int index            = -1;
 int count            = 0;
 while(end_false)
 {
	for(i = 0; i< proc;i++)
	{
	
		if(start[i] == time_quatum || exec[index] == 0)
		{
			
			
			if(flag[i] != 1)
			{
				if(((deadline[i] - time_quatum) - exec[i]) < smallest_slack)
				{
					smallest_slack = (deadline[i] - time_quatum);
					index            = i;
				}
			}
		}
		
		
	}
	if(exec[index] == 0)
			{
				smallest_slack = 10000;
				index=-1;
			}
	if(index!=-1)
	{
		printf("\n From time quantum %d to %d, proc %d", time_quatum,time_quatum+1, index+1);
		exec[index]--;
		if(exec[index] == 0)
		{
			flag[index]=1;
			count++;
		}
	}
	if(count == proc)
	{
		end_false = 0;
	}
 	time_quatum++;
 }
 
}


