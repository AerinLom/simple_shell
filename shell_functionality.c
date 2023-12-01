#include "simple_shell.h"
/**
 * start_new_shell - function prints out a greeting and a username
 * Description: getenv collects the value of "username"
 */

void start_new_shell(void)
{
	char *profile_name = getenv("USER");

	printf("hello, you are logged in\n");

	if (profile_name != NULL)
	{

		printf("profile_name: @%s\n", profile_name);

	}
	else
	{

		printf("Not able to retrieve profile name.\n");

	}
}

/**
 * command_input - function captures user input
 * @type_command: a pointer pointing to a character
 * Description: This function displays user input and stores it
 * Return: 0 if string is empty, otherwise return 1
 */
int command_input(char *type_command)
{
	char *memory;

	memory = readline("\n$ ");

	if (strlen(memory) != 0 && memory != NULL)
	{
		save_command_history(memory);

		strcpy(type_command, memory);

		free(memory);

		return (0);
	}
	else
	{
		free(memory);
		return (1);
	}
}

/**
  *shell_prompt - what is displayed as a prompt on the shell
  */

void shell_prompt(void)
{
	printf("> ");
}
