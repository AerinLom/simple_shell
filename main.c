#include "simple_shell.h"

int main()
{
	int condition, terminate = 0;

	if (standby(&condition) == -1)
	{
		printf("\nFailed to standby");
		exit(terminate);
	}
	return (0);
}
