//Server for named pipe
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
  fd = mkfifo(path,0666);
  if(fd ==-1)
  {
   printf("Unable to create named pipe\n");
  }

  printf("Server is running & writing the data into the named pipe...\n");
  fd =open(path,O_WRONLY);

  write(fd,"Jay Ganesh",10);

  close(fd);

  unlink(path);
  printf("Data is successfully written in Pipe\n");

  return 0;
}
// -o Server