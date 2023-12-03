#include "simple_shell.h"

void shell_print(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}
