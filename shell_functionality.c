#include "simple_shell.h"
/**
 * start_new_shell - function prints out a greeting and a username
 * Description: getenv collects the value of "username"
 */

void start_new_shell(void)
{
	char *profile_name = getenv("USER");

	shell_print("hello, you are logged in\n");

	if (profile_name != NULL)
	{

		shell_print("profile_name: @%s\n");

	}
	else
	{

		shell_print("Not able to retrieve profile name.\n");

	}
}

/**
 * exe_command - function handles system commands
 * @action: system command to be executed
 */

void exe_command(char *command)
{
	char *token_pos, *arguments[MAX_SIZE];
	int argument_count = 0;
	pid_t new_process;

	token_pos = strtok(command, " ");
	while (token_pos != NULL)
	{
		arguments[argument_count] = token_pos;
		argument_count++;
		token_pos = strtok(NULL, " ");
	}
	arguments[argument_count] = NULL;
	if (argument_count == 0)
	{
		return;
	}
	if (strcmp(arguments[0], "exit") == 0) 
	{
		exit_shell();
	}
	if (strcmp(arguments[0], "cd") == 0)
	{
		if (change_dir(arguments) == -1)
		{
			return;
		}
	}
	if (strcmp(arguments[0], "ls") == 0)
	{
		list_dir(arguments);
	}
	new_process = fork();

	if (new_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (new_process == 0)
	{
		if (execve(arguments[0], arguments, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else
	{
		waitpid(new_process, NULL, 0);
	}
}
