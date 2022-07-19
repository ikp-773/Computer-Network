// Experiment - 11 FTP SERVER using TCP
// Adinath Ajith Naik S6 CS-1 06

//SERVER SIDE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>
void main()
{
	printf("SERVER SIDE - FTP\n");
	
	char buffer[50],data[1000],c;
	int sockfd,newsocket;

	memset(data,'\0',sizeof(char)*1000);
	struct sockaddr_in addr1,addr2;

	addr1.sin_family = AF_INET;
	addr1.sin_addr.s_addr = INADDR_ANY;
	addr1.sin_port = 3008;
	int s = sizeof(struct sockaddr_in);
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	bind(sockfd,(struct sockaddr * ) &addr1,sizeof(addr1));

	listen(sockfd,5);

//	newsocket = accept(sockfd,(struct sockaddr *)&addr2,(&s));

	printf("Connection Established");
	
	FILE *fp;	
	
	do
	{
		
		printf("Connection Established");
		newsocket = accept(sockfd,(struct sockaddr *)&addr2,(&s));
		printf("\n*********************");		
		
		pid_t pid = fork();
		
		if(pid ==0)
		{
			printf("\nReceiving Filename from Client: ");
			recv(newsocket,buffer,sizeof(buffer),0);
			printf("%s",buffer);
			fp = fopen(buffer,"r");

			if(fp == NULL)
			{
				printf("Error in Opening File");
				exit(1);
			}
			else
			{
				printf("Sending the content to Client.....\n");
				int i=0;
				while(1)
				{
					c = fgetc(fp);
					if(feof(fp))
						break;
					data[i++] = c;
				}
				
				data[i] ='\0';
				fclose(fp);
				send(newsocket,data,sizeof(data),0);			
			}
			exit(0);
		}

		else if(pid > 0)
		{	
			wait(NULL);
		}
		else if(pid<0)
		{
			exit(1);
		}
		
		printf("\nData is being sent to the client!!!");

	} while(strcmp(buffer,"stop")!=0);

	close (newsocket);
	close(sockfd);
}

// CLIENT 1

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>

void main()
{

	printf("CLIENT 1 - FTP\n");
	char buffer[50],data[1000];
	int sockfd;

	memset(data,'\0',sizeof(char)*1000);

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1,addr2;

	addr2.sin_family = AF_INET;
	addr2.sin_addr.s_addr = INADDR_ANY;
	addr2.sin_port = 3008;

	connect(sockfd,(struct sockaddr *)&addr2,sizeof(addr2));

	do
	{
		printf("Enter the filename:");
		scanf("%s",buffer);
		printf("\nSending filename to server!!!\n");
		send(sockfd,buffer,sizeof(buffer),0);

		printf("\nReceiving Data from the Server!!! \n");
//		printf("\nThe Contents of the file : \n");
		recv(sockfd,data,sizeof(data),0);

		printf("\nThe Contents of the file :\n%s \n",data);
		//printf("Recvd from server:%s\n",data);

	}while(strcmp(buffer,"stop")!=0);

	close(sockfd);
}

// CLIENT 2

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>

void main()
{

	printf("CLIENT 2 - FTP\n");
	char buffer[50],data[1000];
	int sockfd;

	memset(data,'\0',sizeof(char)*1000);

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1,addr2;

	addr2.sin_family = AF_INET;
	addr2.sin_addr.s_addr = INADDR_ANY;
	addr2.sin_port = 3008;

	connect(sockfd,(struct sockaddr *)&addr2,sizeof(addr2));

	do
	{
		printf("Enter the filename:");
		scanf("%s",buffer);
		printf("\nSending filename to server!!!\n");
		send(sockfd,buffer,sizeof(buffer),0);

		printf("\nReceiving Data from the Server!!! \n");
//		printf("\nThe Contents of the file : \n");
		recv(sockfd,data,sizeof(data),0);

		printf("\nThe Contents of the file :\n%s \n",data);
		//printf("Recvd from server:%s\n",data);

	}while(strcmp(buffer,"stop")!=0);

	close(sockfd);
}

/*

INPUT FILES

file1.txt

Welcome to File 1.
You have successfully read the content of file 1. 
You are exiting from File 1.

file2.txt

File 2.
You have successfully read the content of file 2.
You are exiting from File 2. 

OUTPUT

SERVER SIDE

SERVER SIDE - FTP
Connection EstablishedConnection Established
*********************
Receiving Filename from Client: file1.txtSending the content to Client.....
*********************
Data is being sent to the client!!!Connection Established
*********************
Receiving Filename from Client: file2.txtSending the content to Client.....
*********************


CLIENT 1

CLIENT 1 - FTP
Enter the filename:file1.txt

Sending filename to server!!!

Receiving Data from the Server!!! 

The Contents of the file :
Welcome to File 1.
You have successfully read the content of file 1. 
You are exiting from File 1.


CLIENT 2 

Enter the filename:file2.txt

Sending filename to server!!!

Receiving Data from the Server!!! 

The Contents of the file :
File 2.
You have successfully read the content of file 2.
You are exiting from File 2.

*/
