#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("Received SIGINT\n");

  printf("Received signal %d\n",signo);
}

int main()
{
	printf("Able to receive the signal\n");
	signal(SIGINT, sig_handler);
	
	while(1)
	    sleep(1);
	return 0;
}