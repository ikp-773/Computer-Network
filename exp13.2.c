// STOP AND WAIT 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int x2, x1=10,x,nf,i=0,j=0;
	printf("Enter the no of frames: ");
	scanf("%d",&nf);
	printf("\n\n");

	while(nf!=0)
	{
		printf("\nSending frame : %d", i);
		srand(x1++);
		x = rand() %10;
		if(x%2 ==0)
		{
			for(x2 =1; x2<2;x2++)
			{
				printf("\n--->Waiting for %d seconds ", x2);
				sleep(x2);
				printf("\n--->Acknowledge not received ");
			}
		
			printf("\n--->RETRANSMITTING");
			srand(x1++);
			x = rand() % 10;
		}

		printf("\n--->Acknowledgment of %d recevied",i);
		nf = nf-1;
		i++;
		j++;
	}

	printf("\n\n STOP AND WAIT PROCEDURE COMPLETED\n");
}

//OUTPUT

Enter the no of frames: 8

Sending frame : 0
--->Acknowledgment of 0 recevied

Sending frame : 1
--->Acknowledgment of 1 recevied

Sending frame : 2
--->Waiting for 1 seconds 
--->Acknowledge not received 
--->RETRANSMITTING
--->Acknowledgment of 2 recevied

Sending frame : 3
--->Acknowledgment of 3 recevied

Sending frame : 4
--->Acknowledgment of 4 recevied

Sending frame : 5
--->Waiting for 1 seconds 
--->Acknowledge not received 
--->RETRANSMITTING
--->Acknowledgment of 5 recevied

Sending frame : 6
--->Waiting for 1 seconds 
--->Acknowledge not received 
--->RETRANSMITTING
--->Acknowledgment of 6 recevied

Sending frame : 7
--->Acknowledgment of 7 recevied

 STOP AND WAIT PROCEDURE COMPLETED

