#include<stdio.h>
int main ()
{
int proc[100], p_num, block[100], blo_num, temp1[100], temp2[100],alloc[100], count[100];

printf ("\nenter the number of proesss: ");
scanf ("%d", &p_num);
printf ("\nenter number of blocks: ");
scanf ("%d", &blo_num);
printf ("\n");
for (int i = 0;i < p_num;i++)
{
	printf ("\nSize of process %d: ", i);
	scanf ("%d", &pro[i]);
}
for (int j = 0;j<blo_num;j++)
{
	printf ("\nblock size %d: ", j);
	scanf ("%d", &block[j]);
	temp1[j] = block[j];
	temp2[j] = block[j];
}
if (p_num <= blo_num)
{
	printf ("\n\nFirst Fit");
	for (int i = 0; i < p_num; i++)
	{
		for (int j = 0; j < blo_num; j++)
		{
			if (pro[i] <= block[j])
			{
				alloc[j] = pro[i];
				printf("\nprocess %d of size %d is allocated in block:%d of size:%d",i, pro[i], j, block[j]);
				count[i] = 0, block[j] = 0;
				break;
			}	
			else
			count[i] = 1;
		}
	}
for (i = 0; i < p_num; i++)
{
	if (count[i] != 0)
	printf ("\n\nprocess %d of size %d is not allocated", i,
	pro[i]);
}
printf ("\n\nBest Fit");
for (int i = 0; i < blo_num; i++)
{
	for (int j = i + 1; j < blo_num; j++)
	{
		if (temp1[i] > temp1[j])
		{
			int temp = temp1[i];
			temp1[i] = temp1[j];
		  	temp1[j] = temp;
		}
	}
}
for (int i = 0; i < p_num; i++)
{
	for (int j = 0; j < blo_num; j++)
        {
		if (pro[i] <= temp1[j])
	        {
			 alloc[j] = pro[i];
			 printf("\nprocess %d of size %d is allocated in block %d of size %d",i, pro[i], j, temp1[j]);
			 count[i] = 0, temp1[j] = 0;
			 break;
	        }
	        else
	        count[i] = 1;
	}
}
for (int i = 0; i < p_num; i++)
{
	if (count[i] != 0)
	printf ("\nprocess %d of size %d is not allocated", i,pro[i]);
}
printf ("\n\nWorst Fit");
for (int i = 0; i < blo_num; i++)
{
	for (int j = i + 1; j < blo_num; j++)
	{
		if (temp2[i] < temp2[j])
		{
			int temp = temp2[i];
			temp2[i] = temp2[j];
			temp2[j] = temp;
		}
	}
}
for (int i = 0; i < p_num; i++)
{
	for (int j = 0; j < blo_num; j++)
	{
		if (pro[i] <= temp2[j])
		{
			alloc[j] = pro[i];
			printf("\nprocess %d of size %d is allocated in block %d of size %d",i, pro[i], j, temp2[j]);
			count[i] = 0;
			temp2[j] = 0;
			break;
		}
		else
		count[i] = 1;
	}
}
for (int i = 0; i < p_num; i++)
{
	if (count[i] != 0)
	printf ("\nprocess %d of size %d is not allocated", i,pro[i]);
}

else
{
	printf ("\nenter proper input");
}
printf ("\n");
return 0;
}
