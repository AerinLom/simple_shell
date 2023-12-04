#include "simple_shell.h"

int main(void)
{
	char command_size[MAX_SIZE];

	while (1)
	{
		read_input(command_size, sizeof(command_size));

		exe_command(command_size);
	}
	return (0);
}
