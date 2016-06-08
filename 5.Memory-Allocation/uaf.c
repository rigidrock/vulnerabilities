#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 32
#define STRLEN 36

typedef struct _dummy {
  char buffer[BUFLEN];
  int (*leave)(char *);
} dummy;


int leave(char* buf)
{
  memset(buf, 0x00, BUFLEN);
  return 1;
}

dummy *new()
{
  dummy *p;
  p=(dummy *)malloc(sizeof(dummy));
  p->leave=leave;
  printf("addr=%p leave=%p\n", p, p->leave);
  return p;
}

int *destroy(dummy *p)
{
  printf("addr=%p leave=%p\n", p, p->leave);
  (p->leave)(p->buffer);
  free(p);

}

int message(dummy *p, char* msg)
{
  strncpy(p->buffer, msg, BUFLEN-1);
}

int show(dummy *p)
{
  printf("%s\n", p->buffer);
}

int main()
{
  char buf[64];

  buf[read(0, buf, 64)]=0x00;
  vulnerable(buf); 
  return 1; 
}


int vulnerable(char *str)
{
  dummy *bomb;
  char * trigger;

  trigger=malloc(STRLEN);
  printf("addr=%p\n", trigger);
  if(strlen(str) > STRLEN) {
    free(trigger);
  }
  bomb=new();
  if(trigger) {
    strcpy(trigger, str);
    message(bomb, trigger);
    show(bomb);
  }
  else {
    message(bomb, "Unreachable");
    show(bomb);
  }
  destroy(bomb);

  return 1;
}
