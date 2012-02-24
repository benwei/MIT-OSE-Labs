/* pseudo code from 6.828 L1 Case Study: the shell (simplified) */
#include <stdio.h>

/* exec, write, fork, pipe */
#include <unistd.h> 

/* wait() */
#include <sys/types.h>
#include <sys/wait.h>

/* strlen() */
#include <string.h>


#define panic(m) { perror(m) ; _exit(1); }

int main(int argc, char *argv[])
{
	char buf[256] = {0};
	int n = 0, pid = 0;

	int fds[2] = {0};

	if (pipe(fds) < 0) panic("pipe");

	if ((pid = fork ()) == 0) {  // child?
		const char* hello = "hello";

		write(fds[1], hello, strlen(hello));
		printf("w:%s\n", hello);

	} else if (pid > 0) {   // parent?

		read(fds[0], buf, sizeof(buf)-1);
		printf("r:%s\n", buf);
		wait (0);   // wait for child to terminate ; avoid zombie

	} else {
		perror ("fork");
	}
	return 0;
}
