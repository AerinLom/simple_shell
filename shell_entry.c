#include "simple_shell.h"

/**
 * main - function initiates custom shell upon execution
 * Return: 0 upon successful execution
 */
int main(void)
{
	char command_size[MAX_SIZE];

	while (1)
	{
		shell_prompt();

		read_input(command_size, sizeof(command_size));

		exe_command(command_size);
	}
	return (0);
}
