// Experiment 3 P1
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

void main()
{
	int fd1;
	char input_buffer[100];
	char *named_pipe1 = "/home/s6cs106/named_pipe1";
	
	mkfifo(named_pipe1,0666);

	printf("\nEnter the string = ");
	fgets(input_buffer,sizeof(input_buffer),stdin);

	fd1 = open(named_pipe1, O_WRONLY);
	write(fd1,input_buffer,strlen(input_buffer)+1);
	close(fd1);
}


// Experiment - 3 P2
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>


void main()
{
	int i,fd1,fd2,character_count,sentence_count,word_count;
	char input_buffer[100],temp[100];

	char *named_pipe1 = "/home/s6cs106/named_pipe1";
	char *named_pipe2 = "/home/s6cs106/named_pipe2";

	mkfifo(named_pipe1,0666);

	fd1 = open(named_pipe1,O_RDONLY);
	read(fd1, input_buffer,sizeof(input_buffer));
	close(fd1);

	i =0;
	character_count = sentence_count = word_count = 0;
	while(input_buffer[i]!='\0')
	{
		if (input_buffer[i] == ' ')
		{
			word_count++;
		}
		else if (input_buffer[i] == '.')
		{
			sentence_count++;
		}
	
		character_count++;
		i++;
	}

	character_count = character_count - 1;
	word_count = word_count + 1 ;

	sprintf(temp,"No of Characters : %d \nNo of Words : %d \nNo of Sentences : %d ",character_count,word_count,sentence_count);
	
	mkfifo(named_pipe2,0666);

	fd2 = open(named_pipe2,O_WRONLY);
	write(fd2,temp,strlen(temp)+1);
	close(fd2);
}


// Experiment - 3 P3 
// Adinath Ajith Naik S6 CS-1 06

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

void main()
{
	int fd2;
	char output_buffer[100];
	char *named_pipe2 = "/home/s6cs106/named_pipe2";
	
	mkfifo(named_pipe2,0666);

	fd2 = open (named_pipe2, 0666);
	read(fd2,output_buffer,sizeof(output_buffer));
	close(fd2);

	printf("\n%s\n",output_buffer);
}


/* OUTPUT

Enter the string = Welcome to Computer Networks. You are doing named pipes.

No of Characters : 56 
No of Words : 9 
No of Sentences : 2 

*/



