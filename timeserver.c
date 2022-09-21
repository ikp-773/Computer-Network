// Experiment-7 Time Server UDP SERVER


#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<time.h>
#include<string.h>

void main()
{
	printf("UDP Server Side \n");

	char buffer[50];
	int sockfd;

	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 3008;
	int s = sizeof(struct sockaddr_in);
	
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	
	bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	do
	{
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&s);
		pid_t pid = fork();
		if(pid == 0)
		{
			time_t rawtime;
			struct tm * timeinfo;
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			sprintf(buffer,"\nTime is %d : %d : %d ",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
			sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,s);
			printf("\n Time sent to client");
		}
	}while(strcmp(buffer,"stop")!=0);
	
	close (sockfd);
}

// Experiment - 7 Time Server UDP CLIENT - 1 
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

void main()
{
	printf("CLIENT SIDE \n");

	char buffer[50];
	int sockfd;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 3008;
	int s = sizeof(struct sockaddr_in);

	connect(sockfd,(struct sockaddr *)&addr,sizeof(addr));

	do
	{
		printf(" Sending mssg to server: ");
		scanf("%s",buffer);

		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,s);

		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&s);
		printf("Received from server: %s\n",buffer);
	}while(strcmp(buffer,"stop")!=0);

	close (sockfd);
}

// Experiment - 7 UDP CLIENT-2
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

void main()
{
	printf("CLIENT SIDE - 2 \n");

	char buffer[50];
	int sockfd;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 3008;
	int s = sizeof(struct sockaddr_in);

	connect(sockfd,(struct sockaddr *)&addr,sizeof(addr));

	do
	{
		printf(" Sending mssg to server: ");
		scanf("%s",buffer);

		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,s);

		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&s);
		printf("Received from server: %s\n",buffer);
	}while(strcmp(buffer,"stop")!=0);

	close (sockfd);
}




/*  OUTPUT

CLIENT SIDE - 1 
 Sending mssg to server: Hii
Received from server: 
Time is 5 : 57 : 1 
 Sending mssg to server: Computer 
Received from server: 
Time is 5 : 57 : 12 
 Sending mssg to server: Seek
Received from server: 
Time is 5 : 57 : 37 

CLIENT SIDE - 2 
 Sending mssg to server: Hey
Received from server: 
Time is 5 : 57 : 6 
 Sending mssg to server: Networks
Received from server: 
Time is 5 : 57 : 17 
 Sending mssg to server: Hide
Received from server: 
Time is 5 : 57 : 29 

SERVER SIDE

Time sent to client
Time sent to client
Time sent to client
Time sent to client
Time sent to client
Time sent to client

*/
