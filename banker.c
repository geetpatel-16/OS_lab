#include<stdio.h>
void main()
{
	int alloc[10][10],safe[10],Max[10][10],need[10][10],avail[10],done[10];
	int i,j,proc,res,count;
	int trace,;
	
	printf("Enter the no of processes : ");
	scanf("%d", &proc);
	for(i = 0; i< proc; i++)
	{
	
        	done[i] = 0;
        }
        printf("\n\nEnter the no of resources : ");
        scanf("%d", &res);
        
        printf("\n\nEnter the value of Max Matrix for each process : ");
    	for(i=0;i<proc;i++)
    	{
        	printf("\nFor process %d : ",i+1);
        	for(j=0;j<res;j++)
            	{
            		scanf("%d",&Max[i][j]);
        	}
	}
	printf("\n\nEnter the allocation for each process : ");
    	for(i=0;i<proc;i++)
    	{
        	printf("\nFor process %d : ",i+1);
        	for(j=0; j<res;j++)
        	scanf("%d",&alloc[i][j]);
    	}

    	printf("\n\nEnter the Available Resources : ");
    	for(i=0;i<res;i++)
    	{
        	scanf("%d", &avail[i]);
	}
	
   	for(i=0;i<proc;i++)
	{
	        for(j=0;j<res;j++)
	        {
	        
            		need[i][j]=Max[i][j]-alloc[i][j];
               	}
        }
	

	do
        {
        	printf("\n Max matrix:\n");

            	for(i=0;i<proc;i++)
            	{
                	for(j=0;j<res;j++)
                	printf("%d ", Max[i][j]);             	
                }
                for(i=0;i<proc;i++)
                {
                	printf("\n Allocation matrix:\n")
                	for(j =0;j<res;j++)
                    	printf("%d ",alloc[i][j]);
              	}

            trace= -1;

            for(i=0;i<proc;i++)
            {
                if(done[i] == 0)//if not completed
                {
                    trace = i ;
                    for(j=0;j<res;j++)
                    {
                        if(avail[j] < need[i][j])
                        {
                            trace=-1;
                            break;
                        }
                    }
                }
                if(trace!=-1)
                    break;
            }

            if(trace!=-1)
            {
                safe[count]=trace+1;
                count++;
                for(j=0;j<res;j++)
                {
                    avail[j]+=alloc[trace][j];
                    alloc[trace][j] = 0;
                    Max[process][j] = 0;
                    completed[trace] = 1;
                }
            }
        }
        while(count !=proc && trace!=-1);

        if(count == proc)
        
        {
            printf("\nProcess %d runs", trace+1);
            safe[count]=trace+1;
            count++;
            printf("\nThe system is safe\n");
            printf("Safe Sequence :");
            for(i=0;i<proc;i++)
            printf("%d ", safe[i]);
        }
        else
        {
            printf("\nThe system is unsafe");
	}



        
        

