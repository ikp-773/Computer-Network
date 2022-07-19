// Experiment - 10 SMTP SERVER
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>

void main()
{
	printf("SERVER SIDE\n");
	
	char to[50],from[50],subject[50],body[100];
	int sockfd,newsocket;
	int i=0,j=0;

	struct sockaddr_in addr1,addr2;

	addr1.sin_family = AF_INET;
	addr1.sin_addr.s_addr = INADDR_ANY;
	addr1.sin_port = 3008;
	int s = sizeof(struct sockaddr_in);
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	bind(sockfd,(struct sockaddr * ) &addr1,sizeof(addr1));

	listen(sockfd,5);

	newsocket = accept(sockfd,(struct sockaddr *)&addr2,(&s));
		
		printf("Connection Established");
		printf("\nReceiving Mail from Client:\n\n ");


		recv(newsocket,from,sizeof(from),0);
		recv(newsocket,to,sizeof(to),0);
		recv(newsocket,subject,sizeof(subject),0);
		recv(newsocket,body,sizeof(body),0);

		printf("\n From :");
		printf("%s",from);

		printf("\n To :");
		printf("%s",to);		

		printf("\n Subject :");
		printf("%s",subject);

		printf("\n Body :");
		printf("%s",body);

		printf("\n\nSenders Domain : ");
		while(from[i] !='.')
		{
			if(from[i-1] == '@')
			{
				break;
			}
			i++;
		}
		while(from[i] !='.')
		{
			printf("%c",from[i]);
			i++;
		}
		
		printf("\n\nReceivers Domain : ");
		while(to[j] !='.')
		{
			if(to[j-1] == '@')
			{
				break;
			}
			j++;
		}
		while(to[j] !='.')
		{
			printf("%c",to[j]);
			j++;
		}
	
	printf("\n");

	close (newsocket);
	close(sockfd);
}

// Experiment - 10 SMTP CLIENT
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>

void main()
{

	printf("CLIENT SERVER\n");
	char to[50],from[50],subject[50],body[100];
	int sockfd;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1,addr2;

	addr2.sin_family = AF_INET;
	addr2.sin_addr.s_addr = INADDR_ANY;
	addr2.sin_port = 3008;

	connect(sockfd,(struct sockaddr *)&addr2,sizeof(addr2));


		printf("Compose Mail and send to Server:\n\n");

		printf("\nFrom :");
		fgets(from,sizeof(from),stdin);

		printf("\nTo :");
		fgets(to,sizeof(to),stdin);

		printf("\nSubject :");
		fgets(subject,sizeof(subject),stdin);

		printf("\nBody :");
		fgets(body,sizeof(body),stdin);

		send(sockfd,from,sizeof(from),0);
		send(sockfd,to,sizeof(to),0);
		send(sockfd,subject,sizeof(subject),0);
		send(sockfd,body,sizeof(body),0);	

	close(sockfd);
}

/*OUTPUT

CLIENT SERVER
Compose Mail and send to Server:


From :adinath@gmail.com

To :faizan@yahoo.com

Subject :School Outreach Program

Body :The event will be conducted next week.


SERVER SIDE
Connection Established
Receiving Mail from Client:

 
 From :adinath@gmail.com

 To :faizan@yahoo.com

 Subject :School Outreach Program

 Body :The event will be conducted next week.


Senders Domain : gmail

Receivers Domain : yahoo

*/
