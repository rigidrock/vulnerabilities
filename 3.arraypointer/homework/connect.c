#include <sys/type.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int openfd(char *path)
{
  return open(path, O_RDONLY);
}

int readfd(int fd, char *buf, unsigned char size)
{
  return read(fd, buf, size);
}
