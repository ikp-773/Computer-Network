//Experiment 12 Leaky Bucket
// Adinath Ajith Naik S6 Cs1 6 

#include<stdio.h>

int main()
{
	int bucket_size,op_rate,np;
	int i, bucket_rem =0,receive,send;

	printf("\nEnter the bucket size: ");
	scanf("%d",&bucket_size);

	printf("\nEnter the output rate: ");
	scanf("%d",&op_rate);

	printf("\nEnter the no of packets: ");
	scanf("%d",&np);

	int packet[np];

	printf("\nEnter the value of each packet :");
	for(i=1;i<=np;i++)
	{
		printf("\nPacket %d :",i);
		scanf("%d",&packet[i]);
	}

	printf("\nTime-Step\tPacket\t\tAccept\t\tSent\tRemaining\n");

	for(i=1;i<=np;i++)
	{
		if(packet[i] != 0)
		{
			if((packet[i] + bucket_rem) > bucket_size)
				receive = -1;
			else
			{
				receive = packet[i];
				bucket_rem += packet[i] ;
			}
		}
		else
		{
			receive = 0;
		}

		if(bucket_rem != 0)
		{
			if(bucket_rem <= op_rate)
			{
				send = bucket_rem;
				bucket_rem = 0;
		        }	
			else
			{
				send = op_rate;
				bucket_rem -= op_rate;
			}
		} 
		else
		{
			send =0;
		}
		
		if(receive == -1)
			printf("%d\t\t%d\t\tDiscarded\t%d\t\t%d\n",i,packet[i],send,bucket_rem);
		else
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,packet[i],receive,send,bucket_rem);
	}
}

/*

OUTPUT

Enter the bucket size: 5

Enter the output rate: 3

Enter the no of packets: 4

Enter the value of each packet :
Packet 1 :2

Packet 2 :3

Packet 3 :5

Packet 4 :6

Time-Step	Packet		Accept		Sent	Remaining
1		2		2		2		0
2		3		3		3		0
3		5		5		3		2
4		6		Discarded	2		0

*/
