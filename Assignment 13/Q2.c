#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void sighup();
void sigint();
void sigquit();

int main()
{
	int pid;
	pid = fork();
	if (pid == 0)
    {
		signal(SIGHUP, sighup);
		signal(SIGINT, sigint);
		signal(SIGQUIT, sigquit);
		for (;;)
			;
	}

	else
		{
			printf("\n PARENT: sending SIGHUP\n\n");
			kill(pid, SIGHUP);
			sleep(3); // pause 3 sec

			printf("\n PARENT: sending SIGINT\n\n");
			kill(pid, SIGINT);
			sleep(3); // pause 3 sec

			printf("\n PARENT: sending SIGQUIT\n\n");
			kill(pid, SIGQUIT);
			sleep(3); // pause 3 sec
		}
		
  return 0;
}

// function definition of sighup()
void sighup()
{
	signal(SIGHUP, sighup); /* reset signal */
	printf("CHILD: I received a SIGHUP\n");
}

// function definition of sigint()
void sigint()
{
	signal(SIGINT, sigint); /* reset signal */
	printf("CHILD: I received a SIGINT\n");
}

// function definition of sigquit()
void sigquit()
{
	printf("CHILD : Killed\n");
	exit(0);
}
