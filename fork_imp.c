

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int arr[25],no;
int i,j,temp;

void Swap(int i, int j)
{
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Print_array( int no, int arr[])
{
	for (i=0;i<no;i++)
	{
		printf("%d\t",arr[i]);
	}	
	
	printf("\n");	
}


int main()
{
	printf("\n Enter the no of elements : ");
	scanf("%d",&no);
	
	printf("\nEnter the elements : ");
	for ( i=0;i<no;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	pid_t pid;
	pid = fork();
	
	if (pid < 0)
	{
		printf("\nFORK CALL FAILED\n");
	}
	
	else if ( pid == 0)
	{
		printf("-----PARENT PROCESS-----\n");
		printf("Process ID = %d  CHILD PROCESS = %d\n", getppid(),getpid());
		
		for ( i=0;i<no-1;i++)
		{
			for(j=0;j<no-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					Swap (j,j+1);
				}
			}
		}
		
		Print_array(no,arr);
	}
	
	else if ( pid > 0)
	{
		printf("-----CHILD PROCESS-----\n");
		printf("Process ID = %d  PARENT PROCESS = %d\n", getpid(),getppid());
				
		for ( i=0;i<no-1;i++)
		{
			for(j=0;j<no-i-1;j++)
			{
				if(arr[j]<arr[j+1])
				{
					Swap (j,j+1);
				}
			}
		}
		Print_array(no,arr);
	} 
}


/*

OUTPUT

 Enter the no of elements : 5

Enter the elements : 10 5 8 2 36
-----CHILD PROCESS-----
Process ID = 2874  PARENT PROCESS = 2227
36	10	8	5	2	
-----PARENT PROCESS-----
Process ID = 2874  CHILD PROCESS = 2876
2	5	8	10	36	

*/
