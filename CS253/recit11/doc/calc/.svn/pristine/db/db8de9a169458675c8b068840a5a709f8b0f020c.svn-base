#include "calc.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int get_shell()
{
	int pid;
	const char *shell;

	refresh();
	resetterm();
	
	shell=getenv("SHELL");
	if (shell==NULL)
		shell = "/bin/sh";

	pid = fork();
	if (pid==0) {				/* child */
		execl(shell, shell, NULL);
		perror(shell);
		fprintf(stderr, "Can't exec %s\n", shell);
		exit(1);
	}
	wait(0);				/* parent waits for child */

	fixterm();

	return SUCCESS;
}

static func_info fi(get_shell, "sh", "interactive shell");
static func_info fi2(get_shell, "shell", "interactive shell");
