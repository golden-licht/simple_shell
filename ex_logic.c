#include "main.h"

/**
 * ex_logic - Executes the main logic of a shell program, handling user input.
 */

void ex_logic(void)
{
	pid_t id = fork();

	while (1)
	{
		if (id == 0)
		{

			char **argv = NULL;
			int stat;

			disp_prmpt();
			argv = accept_input();

			stat = execve(argv[0], argv, environ);
			if (stat == -1)
			{
				print("Error: No such file or directory");
				print("\n");
			}
		}

		else
		{
			int wstatus;

			wait(&wstatus);
			if (WEXITSTATUS(wstatus) == 98)
			{
				exit(0);
			}

			id = fork();
		}
	}
}
