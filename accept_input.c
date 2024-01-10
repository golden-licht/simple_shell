#include "main.h"

/**
 * is_spaces: Checks if a string, s is only made of
 * spaces or has any characters other than spaces
 * @s: The string
 * 
 * Return: 0, if spaces, 1 otherwise
*/

int is_spaces(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while(s[i] == ' ' || s[i] == '\t')
		i++;

	if (s[i] == '\0')
		return (1);

	return (0);
}

/**
 * accept_input - Reads and returns a line of input from the user.
 *
 * Return: A dynamically allocated string containing the user's input.
 */

char **accept_input(void)
{
	char **argv = NULL;
	char *cmnd = NULL, *cmnd2 = NULL;
	size_t len_cmnd;
	int j = 0;

	int stat = getline(&cmnd, &len_cmnd, stdin);

	/* Handle EOF(Ctrl-D), exit command, and spaces */
	if (stat == -1 || is_spaces(cmnd) || _strcmp("exit\n", cmnd) == 0)
	{
		free(cmnd);
		exit(3);
	}

	while(cmnd[j] == ' ')
		j++;

	cmnd2 = _strdup(cmnd + j);
	free(cmnd);


	cmnd2[_strlen(cmnd2) - 1] = '\0';
	if (_strcmp(cmnd2, "") != 0)
	{
		argv = str_to_arr(cmnd2, " \t");
		argv[0] = find_in_path(argv[0]);
	}
	free(cmnd2);
	return (argv);
}
