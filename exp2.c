// Experiment - 2
// Adinath Ajith Naik
// S6 CS-1 06

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int fd1[2],fd2[2];
char buff[100];
FILE *fp;

int main()
{
	pid_t pid;
	pipe(fd1);
	pipe(fd2);
	
	pid = fork();
	
	if(pid> 0)
	{
		char count[100];
		write(fd1[1],"check.txt",20);
		sleep(3);
		read (fd2[0],count,100);
		printf("%s",count);
	}
	else
	{
		int n = read(fd1[0],buff,100);
		fp = fopen (buff,"r");
		char count[100];
		fgets(count,100,fp);
		write(fd2[1],count,100);
	}	
}


/* 

Check.txt  

Program Running Successfully!!!

OUTPUT

Program Running Successfully!!!

*/




