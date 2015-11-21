#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	printf("hello world (pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) 
	{
		//Fork Failed 
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) 
	{ 	
		//Child Process
		printf("Hello, I am child (pid:%d)\n", (int) getpid());

		char *myargs[3];
		// program: "wc" (word count)
		myargs[0] = strdup("wc");
		//File passed as argument	
		myargs[1] = strdup("exec.c"); 
		//NULL marks end of array
		myargs[2] = NULL;

		//Run wc
		execvp(myargs[0], myargs); 
		printf("This line isn't printed.");
	} else 
	{
		//Parent Process
		int wc = wait(NULL);
		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int) getpid());
	}
	return 0;
}
