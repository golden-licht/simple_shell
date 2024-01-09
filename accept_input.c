#include "main.h"

/**
 * accept_input - Reads and returns a line of input from the user.
 *
 * Return: A dynamically allocated string containing the user's input.
 */

char **accept_input(void)
{
	char **argv = NULL;
	char *cmnd = NULL;
	size_t len_cmnd;

	int stat = getline(&cmnd, &len_cmnd, stdin);

	/* Handle EOF(Ctrl-D) and exit command */
	if (stat == -1 || _strcmp("exit\n", cmnd) == 0)
	{
		free(cmnd);
		exit(3);
	}

	cmnd[_strlen(cmnd) - 1] = '\0';
	argv = str_to_arr(cmnd, " ");
	argv[0] = find_in_path(argv[0]);
	free(cmnd);
	return (argv);
}
