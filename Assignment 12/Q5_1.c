// Server
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#define  MAX_TEXT 512

struct my_msg_st
{
long int my_msg_type;
char some_text[MAX_TEXT];
};

int main()
{
  int running = 1;
  struct my_msg_st data;
  int msgid;
  char buffer[BUFSIZ];

  msgid = msgget( (key_t)1234,0666 | IPC_CREAT);

  if (msgid == -1)
  {
    fprintf(stderr, "Failed to create:\n");
    exit(EXIT_FAILURE);
  }
  while(running)
  {
    printf("Enter some text: ");
    fgets(buffer, BUFSIZ, stdin);
    data.my_msg_type = 1;
    strcpy(data.some_text, buffer);

    if(msgsnd(msgid, (void *)&data, MAX_TEXT, 0) == -1)
    {
      fprintf(stderr, "msg snd failed\n");
      exit(EXIT_FAILURE);
    }
    if(strncmp(buffer, "end", 3) == 0)
    {
      running = 0;
    }
    }
    exit(EXIT_SUCCESS);
}
