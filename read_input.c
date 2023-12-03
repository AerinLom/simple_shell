#include "simple_shell.h"

int read_input(char *input, size_t input_size)
{
	shell_print("$ ");

	if (fgets(input, input_size, stdin) == NULL)
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
	input[strcspn(input, "\n")] = '\0';
	return (1);
}
