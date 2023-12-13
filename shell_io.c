#include "simple_shell.h"
/**
 * shell_print - function outputs the shell to the standard output
 * @user_input: string to be evaluated and printed
 */

void shell_print(const char *user_input)
{
	write(STDOUT_FILENO, user_input, strlen(user_input));
}

void shell_prompt(void)
{
	shell_print("$ ");
	fflush(stdout);
}

/**
 * read_input - evaluates input from user
 * @user_input: the string to be read and evaluated
 * @input_size: total number of characters that can be kept by the buffer
 * Return: return 1 upon successful execution
 */

int read_input(char *user_input, size_t input_size)
{
	if (fgets(user_input, input_size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			shell_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			shell_print("Error reading command.\n");
			exit(EXIT_FAILURE);
		}
	}
	user_input[strcspn(user_input, "\n")] = '\0';
	return (1);
}
