#include "simple_shell.h"

/**
  *string_cpy - copies a string at pointer location
  *@destination: destination
  *@source: source
  *Return: copied string at destination
  */

char *string_cpy(char *destination, char *source)
{
	int c;

	for (c = 0; source[c] != '\0'; c++)
		destination[c] = source[c];
	destination[c] = '\0';
	return (destination);
}
