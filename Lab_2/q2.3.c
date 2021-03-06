#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/*
void childTask()
{
	printf("Salam, saya anak tau\n");
}

void parentTask()
{
	printf("Dan saya adalah bapaknya \n");
}

int main(void)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		childTask();
		exit(EXIT_SUCCESS);
	}
	else if(pid > 0)
	{
		wait(NULL);
		parentTask();
	}
	else
		printf("Unable to create child process");

	return EXIT_SUCCESS;
}
*/

int main(void)
{
	for(int i = 1; i < 13; i++)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			printf("Child process => PPID = %d, PID = %d\n", getppid(), getpid());
			exit(0);
		}
		else
		{
			printf("Parent process => PID = %d\n", getpid());
			printf("Waiting for child processes to finish...\n");
			wait(NULL);
			printf("child process finished\n");
		}
	}
	return EXIT_SUCCESS;
}
