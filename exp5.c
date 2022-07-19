// Experiment - 5 TCP CLIENT
// Adinath Ajith Naik
// S6 CS-1 06

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>

void main()
{

	printf("CLIENT SERVER\n");
	char buffer[50];
	int sockfd;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1,addr2;

	addr2.sin_family = AF_INET;
	addr2.sin_addr.s_addr = INADDR_ANY;
	addr2.sin_port = 3008;

	connect(sockfd,(struct sockaddr *)&addr2,sizeof(addr2));

	do
	{
		printf("Sending mssg to server:");
		scanf("%s",buffer);
		send(sockfd,buffer,sizeof(buffer),0);
		recv(sockfd,buffer,sizeof(buffer),0);
		printf("Recvd from server:%s\n",buffer);

	}while(strcmp(buffer,"stop")!=0);

	close(sockfd);
}

// Experiment - 5 TCP SERVER
// Adinath Ajith Naik
// S6 CS-1 06

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>

void main()
{
	printf("SERVER SIDE\n");
	
	char buffer[50];
	int sockfd,newsocket;

	struct sockaddr_in addr1,addr2;

	addr1.sin_family = AF_INET;
	addr1.sin_addr.s_addr = INADDR_ANY;
	addr1.sin_port = 3008;
	int s = sizeof(struct sockaddr_in);
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	bind(sockfd,(struct sockaddr * ) &addr1,sizeof(addr1));

	listen(sockfd,5);

	newsocket = accept(sockfd,(struct sockaddr *)&addr2,(&s));

	do
	{
		printf("Connection Established");
		printf("\nReceiving Message from Client: ");
		recv(newsocket,buffer,sizeof(buffer),0);
		printf("%s",buffer);
		printf("\nEnter the message:");
		scanf("%s",buffer);
		send(newsocket,buffer,sizeof(buffer),0);
	
	} while(strcmp(buffer,"stop")!=0);

	close (newsocket);
	close(sockfd);
}


/* OUTPUT

SERVER SIDE
Connection Established
Receiving Message from Client: Hello
Enter the message:Hii 
Connection Established
Receiving Message from Client: Computer
Enter the message:Networks
Connection Established
Receiving Message from Client: stop
Enter the message:stop

CLIENT SERVER
Sending mssg to server:Hello
Recvd from server:Hii
Sending mssg to server:Computer
Recvd from server:Networks
Sending mssg to server:stop
Recvd from server:stop

*/

