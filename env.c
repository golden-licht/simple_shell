#include "main.h"

/**
 * _env - Displays the environment variables.
 */

void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		print(environ[i]);
		print("\n");
		i++;
	}
}
