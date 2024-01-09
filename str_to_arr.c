#include "main.h"

/**
 * str_to_arr - Converts an input string to an array of strings
 * based on a specified delimiter.
 * @string: Original string to be split.
 * @delim: Delimiter used to split the string.
 *
 * Return: Pointer to the array of strings.
 */

char **str_to_arr(char *string, char *delim)
{
	char *str;
	char **arr;
	char *temp;
	int i = 0;

	if (string == NULL || delim == NULL)
		return (NULL);

	str = _strdup(string);
	if (str == NULL)
		return (NULL);

	arr = malloc(sizeof(char *) * (strlen(string) + 1));
	if (arr == NULL)
	{
		free(str);
		return (NULL);
	}

	temp = strtok(str, delim);

	while (temp)
	{
		arr[i] = temp;
		temp = strtok(NULL, delim);
		i++;
	}

	arr[i] = NULL;
	return (arr);
}
