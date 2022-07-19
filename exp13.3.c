// GO BACK ARQ

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int n,ws;
	printf("Enter the no of packets: ");
	scanf("%d",&n);

	printf("\nEnter the window size: ");
	scanf("%d",&ws);

	int k, i=1,z=0,tt=0,x;

	srand(time(0));
	
	while(i<=n)
	{
		z =0;
		for(k=i;k<i+ws && k<=n;k++)
		{
			printf("\n\nSending the packet %d", k);
			tt++;
		}

		for(k=i;k<i+ws && k<=n;k++)
		{
			x = rand()%2;
			if(x==0)
			{
				printf("\n--->Acknowledgment of packet %d not received !!!",k);
				printf("\n--->RETRANSMITTING");
				break;
			}
			else
			{
				printf("\n--->Acknowledgement of %d recevied",k);
				z = z+1;
			}
		}
		
		i = z+i;
	}
	
	printf("\n\nPackets are sent and resent %d no of times\n\n",tt);
}

//OUTPUT

Enter the no of packets: 12
Enter the window size: 3

Sending the packet 1

Sending the packet 2

Sending the packet 3
--->Acknowledgment of packet 1 not received !!!
--->RETRANSMITTING

Sending the packet 1

Sending the packet 2

Sending the packet 3
--->Acknowledgement of 1 recevied
--->Acknowledgment of packet 2 not received !!!
--->RETRANSMITTING

Sending the packet 2

Sending the packet 3

Sending the packet 4
--->Acknowledgment of packet 2 not received !!!
--->RETRANSMITTING

Sending the packet 2

Sending the packet 3

Sending the packet 4
--->Acknowledgement of 2 recevied
--->Acknowledgement of 3 recevied
--->Acknowledgment of packet 4 not received !!!
--->RETRANSMITTING

Sending the packet 4

Sending the packet 5

Sending the packet 6
--->Acknowledgement of 4 recevied
--->Acknowledgment of packet 5 not received !!!
--->RETRANSMITTING

Sending the packet 5

Sending the packet 6

Sending the packet 7
--->Acknowledgment of packet 5 not received !!!
--->RETRANSMITTING

Sending the packet 5

Sending the packet 6

Sending the packet 7
--->Acknowledgement of 5 recevied
--->Acknowledgment of packet 6 not received !!!
--->RETRANSMITTING

Sending the packet 6

Sending the packet 7

Sending the packet 8
--->Acknowledgement of 6 recevied
--->Acknowledgment of packet 7 not received !!!
--->RETRANSMITTING

Sending the packet 7

Sending the packet 8

Sending the packet 9
--->Acknowledgment of packet 7 not received !!!
--->RETRANSMITTING

Sending the packet 7

Sending the packet 8

Sending the packet 9
--->Acknowledgment of packet 7 not received !!!
--->RETRANSMITTING

Sending the packet 7

Sending the packet 8

Sending the packet 9
--->Acknowledgment of packet 7 not received !!!
--->RETRANSMITTING

Sending the packet 7

Sending the packet 8

Sending the packet 9
--->Acknowledgment of packet 7 not received !!!
--->RETRANSMITTING

Sending the packet 7

Sending the packet 8

Sending the packet 9
--->Acknowledgement of 7 recevied
--->Acknowledgment of packet 8 not received !!!
--->RETRANSMITTING

Sending the packet 8

Sending the packet 9

Sending the packet 10
--->Acknowledgement of 8 recevied
--->Acknowledgement of 9 recevied
--->Acknowledgement of 10 recevied

Sending the packet 11

Sending the packet 12
--->Acknowledgement of 11 recevied
--->Acknowledgement of 12 recevied

Packets are sent and resent 44 no of times



