/* pseudo code from 6.828 L1 Case Study: the shell (simplified) */
#include <stdio.h>

/* open() */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* write() */
#include <unistd.h> 

/* user defines */
#define UCAT_BUF_SIZE 512

main(int argc, char *argv[])
{
  int fd, n;
  char buf[UCAT_BUF_SIZE];
  if(argc > 1)
        fd = open(argv[1], 0); /* read from file */
  else
  	fd = 0; /* read from stdin */

  while((n = read(fd, buf, UCAT_BUF_SIZE)) > 0)
      write(1, buf, n);

  close(fd);
  return 0;
}
