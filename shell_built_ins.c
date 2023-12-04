#include "simple_shell.h"

int change_dir(char *arguments[])
{
	if (arguments[1] != NULL)
	{
		if (chdir(arguments[1]) == -1)
		perror("chdir");
		return (-1);
	}

	else
	{
	shell_print("cd: missing argument\n");

	return (-1);
	}

	return (0);
}

void exit_shell(void)
{
shell_print("Exiting shell.\n");
exit(EXIT_SUCCESS);
}

void list_dir(char *arguments[])
{
	pid_t new_process;

	new_process = fork();

	if (new_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (new_process == 0)
	{
		execve("/bin/ls", arguments, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(new_process, NULL, 0);
	}
}
