// CLIENT for the named Pipe
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
  int fd = 0;
  char *path = "/tmp/mypipe";
  char Buffer[100];

  printf("Client is running,reading data from named Pipe...\n");
  fd =open(path,O_RDONLY);

  read(fd,Buffer,10);

  printf("Data from the Pipe is : %s\n",Buffer);

  return 0;
}
// -o Client
// run server before running client