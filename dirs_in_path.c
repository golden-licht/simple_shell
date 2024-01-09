#include "main.h"

/**
 * dirs_in_path - Splits the PATH environment
 * variable into an array of strings.
 *
 * Return: Pointer to an array of strings representing directories in the PATH.
 */

char **dirs_in_path()
{
	char *value = getenv("PATH");
	char *val = _strdup(value);
	char **arr = str_to_arr(val, ":");

	free(val);
	return (arr);
}
