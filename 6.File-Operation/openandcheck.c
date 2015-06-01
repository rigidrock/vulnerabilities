#include <stdio.h>
#include <unistd.h>
#define MAX 32
#define TMP "/tmp/xxx"

int main()
{
  char path[]=TMP;
  FILE *fp;
  char buf[MAX];
  int n;

  n=fread(buf, 1, MAX, stdin);
  if(access(path, W_OK)==-1) return;
  fp=fopen(TMP, "w");
  fwrite(buf, 1, n, fp);
  fclose(fp);
}
