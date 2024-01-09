#include "main.h"

/**
 * dirs_in_path - Splits the PATH environment
 * variable into an array of strings.
 *
 * Return: Pointer to an array of strings representing directories in the PATH.
 */

char **dirs_in_path()
{
	char *val = getenv("PATH");
	char **argv = str_to_arr(val, ":");

	return (argv);
}
