#include "main.h"

/**
 * ex_logic - Executes the main logic of a shell program, handling user input.
 * @av: The first argument to main
 */

void ex_logic(char *av)
{
	pid_t id = fork();

	while (1)
	{
		if (id == 0)
		{
			char **argv = NULL;
			int stat;

			/*disp_prmpt();*/
			argv = accept_input();

			if (argv == NULL)
				exit(-1);

			stat = execve(argv[0], argv, environ);
			if (stat == -1)
			{
				int i = 0;

				while (argv[i])
				{
					free(argv[i]);
					i++;
				}
				free(argv);
				perror(av);
			}
		}
		else
		{
			int wstatus;

			wait(&wstatus);
			if (WEXITSTATUS(wstatus) == 3)
			{
				exit(0);
			}

			id = fork();
		}
	}
}
