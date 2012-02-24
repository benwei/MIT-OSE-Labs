/* pseudo code from 6.828 L1 Case Study: the shell (simplified) */
#include <stdio.h>

/* for exec, write, fork */
#include <unistd.h> 
/* for wait() */
#include <sys/types.h>
#include <sys/wait.h>


static void newline(void)
{
	const char *newline = "\n";
	write(1, newline, 1);
}

char *targv[] = {"sleep","2", NULL};
char ** readcmd(char *buf, char **cmd) {
	*cmd = "/bin/sleep";
	/* FIXME: gets and parser buf to args */
	return targv; 
}	

int main(int argc, char *argv[])
{
	char buf[256] = {0};
	char *cmd = NULL;
	char **args = NULL;
	int pid = 0;
	while (1) {
		newline();
		write (1, "$ ", 2);
		args = readcmd (buf, &cmd);   // parse user input
		if ((pid = fork ()) == 0) {  // child?
			execv (cmd, args);
		} else if (pid > 0) {   // parent?
			wait (0);   // wait for child to terminate
		} else {
			perror ("fork");
			sleep(1000);
		}
	}
	return 0;
}
