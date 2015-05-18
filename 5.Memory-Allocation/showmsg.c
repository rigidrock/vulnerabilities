#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX 32
#define ROLE 3
#define FAIL -1

struct login {
  char name[MAX+1];
  char pass[MAX+1];
  char mseg[MAX+1];
};

struct login role[]={ 
{"guest", "", ""}, 
{"user", "", "Hello, user!"},
{"admin", "", "Hello, admin!"},
};

int main()
{
  char user[MAX+1];
  char pass[MAX+1];
  int len;
  int id;

  initial();
  while(1) {
    getstr("Username", user);
    getstr("Password", pass);

    if((id=auth(user, pass))!=FAIL) {
      readmsg(id);
    }
  }
}

int initial()
{
  int i;

  srand(getpid());
  for(i=0;i<ROLE; i++) 
    snprintf(role[i].pass, MAX, "%08d", rand());
  
  return;
}

int getstr(char *prompt, char *string)
{
  int len;

  printf("Enter %s:", prompt);
  fgets(string, MAX+1, stdin);
  len=strlen(string);
  len=(len<MAX) ? (len-1) : MAX;
  string[len]='\0';
  return;
}

int auth(char *user, char *pass)
{
  char *key;
  int i;

  for(i=0; strcmp(user, role[i].name) && i<ROLE; i++);
  if (i>=ROLE) return FAIL;
  else if(i==0) return 0;
  key=role[i].pass;
  if(strcmp(pass, key)==0) return i;
  return FAIL;
}

int readmsg(int id)
{
  char *name;
  char *msg;
  int i;

  printf("1- Show Message, 0- Logout:");
  i=getc(stdin);
  if (i==(int)'1') {
    if(id > 0)  {
      name=role[id].name;
      msg=role[id].mseg;
    }
    printf("%s's message: %s\n", name, msg);
  }
  getc(stdin);
  
  return;
}
