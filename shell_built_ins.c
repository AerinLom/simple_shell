#include "simple_shell.h"

/**
 * change_dir - function switches from current directory
 * @stored_arguments: arguments stored inside strings of an array
 * Return: 0 on successful execution, otherwise return -1
 */

int change_dir(char *stored_arguments[])
{
	if (stored_arguments[1] != NULL)
	{
		if (chdir(stored_arguments[1]) != 0)
		perror("chdir");
		return (-1);
	}

	else if (stored_arguments[1] == NULL)
	{
	shell_print("cd: missing argument\n");
	return (-1);
	}

	return (0);
}

/**
 * exit_shell - function disconnects from custom shell and prints message
 */

void exit_shell(void)
{
exit(EXIT_SUCCESS);
}

/**
 * list_dir - fucnction establishes a list of contents of a current directory
 * @stored_arguments: commands arguments stored inside an array of strings
 */

void list_dir(char *stored_arguments[])
{
	pid_t new_process_id;

	new_process_id = fork();

	if (new_process_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (new_process_id == 0)
	{
		execve("/bin/ls", stored_arguments, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(new_process_id, NULL, 0);
	}
}
