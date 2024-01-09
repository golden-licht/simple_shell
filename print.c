#include "main.h"

/**
 * print - Prints a string to stdout
 * @s: The string to be printed
*/

void print(char *s)
{
	write(1, s, _strlen(s) + 1);
}
