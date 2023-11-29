#include "simple_shell.h"
/**
 * start_new_shell - function prints out a greeting and a username
 * Description: getenv collects the value of "username"
 */

void start_new_shell(void)
{
	char *profile_name = getenv("username");

	printf("hello, you are logged in\n");

	printf("profile_name: @%s\n", profile_name);
}
