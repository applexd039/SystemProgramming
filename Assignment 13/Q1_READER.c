// Reader
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

    printf("Client is running and reading the data from the named pipe\n");
    fd = open(path,O_RDONLY);

    read(fd,Buffer,19);

    printf("Data from the pipe is : %s\n",Buffer);
    return 0;
}
