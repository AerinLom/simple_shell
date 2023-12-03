#include "simple_shell.h"
/**
 * start_new_shell - function prints out a greeting and a username
 * Description: getenv collects the value of "username"
 */
void start_new_shell(void)
{
	char *user_avatar = getenv("USER");

	shell_print("hello, you are logged in\n");

	if (user_avatar != NULL)
	{
		shell_print("user_avatar: @%s\n");
	}
	else
	{
		shell_print("Not able to retrieve user_avatar.\n");
	}
}
/**
 * exe_command - function handles system commands
 * @command: input string that is implemented by the system
 * Description: this function analysis the input from user and
 * checks if basic linux system commands are being executed
 */
void exe_command(char *command)
{
	char *token_stream, *argument_param[MAX_SIZE];
	int argument_tally = 0;
	pid_t new_process_id;

	token_stream = strtok(command, " ");

	while (token_stream != NULL)
	{
		argument_param[argument_tally] = token_stream;
		argument_tally++;
		token_stream = strtok(NULL, " ");
	}
	argument_param[argument_tally] = NULL;
	if (argument_tally == 0)
	{
		return;
	}
	if (strcmp(argument_param[0], "exit") == 0)
	{
		exit_shell();
	}
	if (strcmp(argument_param[0], "cd") == 0)
	{
		if (change_dir(argument_param) == -1)
		{
			return;
		}
	}
	if (strcmp(argument_param[0], "ls") == 0)
	{
		list_dir(argument_param);
	}
	new_process_id = fork();
	if (new_process_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (new_process_id == 0)
	{
		if (execve(argument_param[0], argument_param, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else
	{
		waitpid(new_process_id, NULL, 0);
	}
}
