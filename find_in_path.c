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
	int i = 0;

	while (dirs[i])
	{
		int len = _strlen(dirs[i]) + _strlen(file_name) + 2;
		char *full_path = malloc(sizeof(char) * len);
		int status;

		strcpy(full_path, dirs[i]);
		strcat(full_path, "/");
		strcat(full_path, file_name);

		status = stat(full_path, statbuf); /* 0 if found, -1 otherwise */

		if (status == 0)
		{
			free(statbuf);
			return (full_path);
		}
		i++;
	}

	free(statbuf);
	return (file_name); /* File was not found */
}
