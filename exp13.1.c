// Experiment 13 Sliding Window Protocols
// Adinath Ajith Naik S6 CS 1  06


//SELECTIVE REPEAT

#include<stdio.h>
#include<stdlib.h>

int input(int a[], int frame_size)
{
	printf("\n\n INPUT\n\n");
	for(int i = 1; i<= frame_size;i++)
	{
		printf("Enter the value of Frame[%d] : ",i);
		scanf("%d",&a[i]);
		printf("\n\n");
	}
	printf("\n\n");
	return 1;
}

int display(int a[], int frame_size)
{
	printf("\n\n DISPLAY \n\n");
	for(int i = 1; i<= frame_size;i++)
	{
		printf("Frame[%d] : %d ",i,a[i]);
		printf("\n\n");
	}
	printf("\n\n");
	return 1;
}

int selective_repeat(int frame[], int window_size,int frame_size)
{
	int nt=0,k=0,i,x;
	int left[10000] = {-1};
	for(i=1;i<frame_size;i++)
	{
		int flag = rand()%2;
		if(flag)
		{
			printf("Frame[%d] with value %d is acknowledged!! \n\n",i,frame[i]);
			nt++;
		}
		else
		{
			printf("Frame[%d] with value %d is not acknowledged!! \n\n",i,frame[i]);
			left[k++] = frame[i];
			nt++;
		}

		if(i%window_size ==0)
		{
			for (x=0; x<k;x++)
			{
				printf("Frame[%d] with value %d is retransmmitted!! \n\n",x,left[x]);
				nt++;
				printf("Frame[%d] with value %d is acknowledged on 2nd transmission!! \n\n",x,left[x]);
			} k=0;
		}	
	}

	for(i=0;i<k;i++)
	{
		printf("Frame[%d] with value %d is retransmitted!! \n\n",i,left[i]);
		nt++;
		printf("Frame[%d] with value %d is acknowledged on 2nd transmission!! \n\n",i,left[i]);
	}

	printf("Total Transmission : %d \n\n",nt);
	return 0;	
}

int main()
{
	int frames[50], window_size,frame_size;
	printf("\n\n SELECTIVE REPEAT\n\n");
	printf("\n\nEnter the window size:");
	scanf("%d",&window_size);
	printf("\n\nEnter the no of frames to be sent:");
	scanf("%d",&frame_size);

	input(frames,frame_size);
	display(frames,frame_size);
	selective_repeat(frames,window_size,frame_size);
	return 0;
}

// OUTPUT

SELECTIVE REPEAT



Enter the window size:5
Enter the no of frames to be sent:10


INPUT

Enter the value of Frame[1] : 1
Enter the value of Frame[2] : 2
Enter the value of Frame[3] : 3
Enter the value of Frame[4] : 4
Enter the value of Frame[5] : 5
Enter the value of Frame[6] : 6
Enter the value of Frame[7] : 7
Enter the value of Frame[8] : 8
Enter the value of Frame[9] : 9
Enter the value of Frame[10] : 10

DISPLAY 
Frame[1] : 1 
Frame[2] : 2 
Frame[3] : 3 
Frame[4] : 4 
Frame[5] : 5
Frame[6] : 6 
Frame[7] : 7 
Frame[8] : 8 
Frame[9] : 9 
Frame[10] : 10 



Frame[1] with value 1 is acknowledged!! 

Frame[2] with value 2 is not acknowledged!! 

Frame[3] with value 3 is acknowledged!! 

Frame[4] with value 4 is acknowledged!! 

Frame[5] with value 5 is acknowledged!! 

Frame[0] with value 2 is retransmmitted!! 

Frame[0] with value 2 is acknowledged on 2nd transmission!! 

Frame[6] with value 6 is acknowledged!! 

Frame[7] with value 7 is not acknowledged!! 

Frame[8] with value 8 is not acknowledged!! 

Frame[9] with value 9 is acknowledged!! 

Frame[0] with value 7 is retransmitted!! 

Frame[0] with value 7 is acknowledged on 2nd transmission!! 

Frame[1] with value 8 is retransmitted!! 

Frame[1] with value 8 is acknowledged on 2nd transmission!! 

Total Transmission : 12 
