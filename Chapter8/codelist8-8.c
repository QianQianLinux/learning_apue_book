//程序清单8-8 exec函数实例
//要正确运行程序需将echoall拷贝到某PATH环境变量目录下
//原因见http://blog.csdn.net/abcdef0966/article/details/5725541

#include "apue.h"
#include <sys/wait.h>

char	*env_init[] = { "USER=unknown", "PATH=/tmp", NULL };

int main(void)
{
	pid_t	pid;
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) { /* specify pathname, specify environment */
	   if (execle("./echoall",
		"echoall", "myarg1", "MY ARG2", (char *)0, env_init) < 0)
	      err_sys("execle error");
	}

	if (waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");
	
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) { /* specify filename, inherit environment */
	    if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
		err_sys("execlp error");
	}

	exit(0);

}
