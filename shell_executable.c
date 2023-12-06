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
 * path_check - function evaluates whether command in path exists
 * @command: the command to be evaluated
 * Return: 0 if command is built in, otherwise -1
 */
int path_check(char *command)
{
	char *route, *token_stream;
	char *route_env = getenv("PATH");
	char route_buffer[MAX_SIZE];

	if (access(command, F_OK | X_OK) == 0)
	{
		return (0);
	}
	if (route_env == NULL)
	{
		shell_print("Error: PATH environment variable not set.\n");
		return (-1);
	}
	string_cpy(route_buffer, route_env);
	token_stream = strtok(route_buffer, ":");

	while (token_stream != NULL)
	{
		route = (char *)malloc(strlen(token_stream) + strlen(command) + 2);
		if (route == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		string_cpy(route, token_stream);
		strcat(route, "/");
		strcat(route, command);

		if (access(route, F_OK | X_OK) == 0)
		{
			free(route);
			return (0);
		}
		free(route);
		token_stream = strtok(NULL, ":");
	}
	return (-1);
}

/**
  *handle_builtins - function that handles custom built ins
  *@argument_param: an array of command arguments
  *@current_env: the current enviroment of the shell
  */

void handle_builtins(char **argument_param, char **current_env)
{
	if (strcmp(argument_param[0], "exit") == 0)
	{
		exit_shell();
	}
	else if (strcmp(argument_param[0], "cd") == 0)
	{
		change_dir(argument_param);
	}
	else if (strcmp(argument_param[0], "ls") == 0)

	{
		list_dir(argument_param);
	}
	else if (strcmp(argument_param[0], "env") == 0)
	{
		while (*current_env)
		{
			shell_print(*current_env++);
			shell_print("\n");
		}
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
	char *token_stream, *argument_param[MAX_SIZE], **current_env = environ;
	int argument_tally = 0;
	pid_t new_process_id;

	token_stream = strtok(command, " ");
	while (token_stream != NULL)
	{
		argument_param[argument_tally++] = token_stream;
		token_stream = strtok(NULL, " ");
	}
	argument_param[argument_tally] = NULL;
	if (argument_tally == 0)
	{
		return;
	}
	handle_builtins(argument_param, current_env);
	if (path_check(argument_param[0]) == -1
	&& strcmp(argument_param[0], "cd") != 0)
	{
		shell_print(argument_param[0]);
		shell_print(": not found\n");
	}
	else
	{
		new_process_id = fork();
		if (new_process_id == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (new_process_id == 0)
		{
			execve(argument_param[0], argument_param, environ), exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(new_process_id, NULL, 0);
		}
	}
}
