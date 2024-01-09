#include "main.h"

/**
 * find_in_path - Searches for a file in the directories
 * listed in the PATH variable.
 * @file_name: Name of the file to search for.
 *
 * Return: The full path of the found file, or NULL if not found.
 */

char *find_in_path(char *file_name)
{
	struct stat *statbuf = malloc(sizeof(struct stat));
	char **dirs = dirs_in_path();
	char *full_path = NULL;
	int i = 0, found = 0;

	while (dirs[i])
	{
		int len = _strlen(dirs[i]) + _strlen(file_name) + 2;
		int status;

		full_path = malloc(sizeof(char) * len);
		if (full_path == NULL)
			break;

		_strcpy(full_path, dirs[i]);
		_strcat(full_path, "/");
		_strcat(full_path, file_name);

		status = stat(full_path, statbuf); /* 0 if found, -1 otherwise */
		if (status == 0)
		{
			found = 1;
			break;
		}
		free(full_path);
		i++;
	}
	for (i = 0; dirs[i]; i++)
	{
		free(dirs[i]);
	}

	free(dirs);
	free(statbuf);

	if (found)
		return (full_path);
	return (file_name); /* File was not found */
}
