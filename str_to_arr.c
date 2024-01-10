#include "main.h"

/**
 * arr_size - Finds the size of the array needed for
 * the str_to_arr function
 * @string: Original string to be split.
 * @delim: Delimiter used to split the string.
 *
 * Return: Pointer to the array of strings.
 */

int arr_size(char *string, char *delim)
{
	char *str = NULL, *temp = NULL;
	int size = 0;

	str = _strdup(string);
	if (str == NULL)
		return (-1);

	/* str used to count the size of the array */
	temp = strtok(str, delim);
	while (temp)
	{
		size++;
		temp = strtok(NULL, delim);
	}
	free(str);

	return (size);
}

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
	char **argv = NULL;
	char *str = NULL, *temp = NULL;
	int i = 0;
	int size = arr_size(string, delim);

	if (string == NULL || delim == NULL)
		return (NULL);

	str = _strdup(string);
	if (str == NULL)
		return (NULL);

	argv = malloc(sizeof(char *) * (size + 1));
	if (argv == NULL)
	{
		free(str);
		return (NULL);
	}
	temp = strtok(str, delim);
	while (temp)
	{
		int j;

		argv[i] = _strdup(temp);
		if (argv[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(argv[j]);
				free(argv);
				free(str);
			}
			return (NULL);
		}
		temp = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	free(str);
	return (argv);
}
