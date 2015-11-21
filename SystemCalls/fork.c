#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main (int argc, char *argv[])
{
	printf("Hello World (pid:%d)\n", (int) getpid());
	
	//Fork Call Returns 0 for Child, Current PID for Parent
	int rc = fork();
	if(rc<0)
	{
		//fork() never returns <0
		fprintf(stderr,"Fork Failed!\n");
		exit(1);
	}
	else if (rc==0)
	{
		//Child process
		printf("Hello, I am child with pid:%d\n", (int) getpid());
	}
	else
	{
		//Parent process
		printf("Hello, I am parent of %d with my pid:%d\n", rc, (int) getpid());
	}
	//The output is non-deterministic, i.e, the order of child and parent processes being executed is not definite, and may vary each time.
	return 0;
}
