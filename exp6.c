// Experiment-6 UDP SERVER
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

void main()
{
	printf("UDP SERVER SIDE \n");

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
		printf("Connection Established\n");
		printf("Receiving messge from client: ");
	
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&s);
		printf("%s",buffer);
		printf("\nEnter the message: ");
		scanf("%s",buffer);

		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,s);
	}while(strcmp(buffer,"stop")!=0);
	
	close (sockfd);
}

// Experiment - 6 UDP CLIENT
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

void main()
{
	printf("UDP CLIENT SIDE \n");

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

/*OUTPUT

UDP SERVER SIDE
Connection Established
Receiving messge from client: Hii
Enter the message: Hey
Connection Established
Receiving messge from client: Welcome
Enter the message: Thankyou 
Connection Established
Receiving messge from client: stop
Enter the message: stop


UDP CLIENT SIDE 
 Sending mssg to server: Hii
Received from server: Hey
 Sending mssg to server: Welcome
Received from server: Thankyou
 Sending mssg to server: stop
Received from server: stop

