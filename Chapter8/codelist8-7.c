//#include "apue.h"	/* 添加codelist15-3或10-17后，必须注释该行*/
#include "codelist15-3.c"

static void charatatime(char *);

int main(void)
{
	pid_t	pid;
	TELL_WAIT();

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		WAIT_PARENT();	/* parent goes first */
		charatatime("output from child\n");
	} else {
		charatatime("output from parent\n");
		TELL_CHILD(pid);
	}
	exit(0);
}

static void charatatime(char *str)
{
	char	*ptr;
	int	c;

	setbuf(stdout, NULL);	/* set unbuffered */
	for (ptr = str; (c = *ptr++) != 0; )
		putc(c, stdout);
}
