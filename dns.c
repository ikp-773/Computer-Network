// Experiment - 9 DNS CLIENT


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
		printf(" Sending DNS to server: ");
		scanf("%s",buffer);

		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,s);

		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&s);
		printf("Received from server: %s\n",buffer);
	}while(strcmp(buffer,"stop")!=0);

	close (sockfd);
}


// Experiment-9 DNS SERVER
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

void main()
{
	printf("UDP Server Side \n");

	char buffer[50];
	char dns[100],ip[80];
	int sockfd;

	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 3008;
	int s = sizeof(struct sockaddr_in);
	
	sockfd = socket(AF_INET,SOCK_DGRAM,0);

	FILE *fp;

	bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	printf("Connection Established\n");
	do
	{		
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&s);
		printf("\nClient: %s",buffer);
		fp = fopen("dnsrecord.txt","r");

	 	if( fp == NULL)
		{
			printf("Error in opening file");
			exit(1);
		}	
		
	while(fscanf(fp,"%s\t%s",dns,ip)!= EOF)
	{
		if(strcmp(dns,buffer)==0)
		{
			break;
		}
		else
		{
			strcpy(ip,"IP ADDRESS NOT FOUND");
		}
	}
	fclose(fp);
	sendto(sockfd,ip,sizeof(ip),0,(struct sockaddr *)&addr,s);
	
	}while(strcmp(buffer,"stop")!=0);
	
	close (sockfd);
}

/*OUTPUT

dnsrecord.txt

www.google.com	192.24.26.20
www.mbcet.ac.in	108.52.69.35
www.facebook.com	200.36.47.85
www.youtube.com	155.69.54.78
www.ieee.org	148.96.57.55

CLIENT SIDE 
 Sending DNS to server: www.ieee.org
Received from server: 148.96.57.55
 Sending DNS to server: www.google.com
Received from server: 192.24.26.20
 Sending DNS to server: www.youtube.com
Received from server: 155.69.54.78
 Sending DNS to server: www.hexagon.com
Received from server: IP ADDRESS NOT FOUND


SERVER SIDE

Connection Established

Client: www.ieee.org
Client: www.google.com
Client: www.youtube.com
Client: www.hexagon.com

*/
