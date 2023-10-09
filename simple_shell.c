#include "head.h"

/**
 * main - main finction
 * Descreption: main function of our simple shell
 * Return: 0 success
 */

int main(void)
{
	char command[50000],  **args = NULL, *path = NULL;
	int status = 0,  pid_t id;

	while (1)
	{
		_putstring("$ ");
		fflush(stdin);
		if (gets(command, sizeof(char *), stdin) == NULL)
		{
			break;
		}
		if (command[_strlen(command) - 1] == '\n')
			command[_strlen(command) - 1] = '\0';
		args = fill(command);
		if (check(args[0]))
			continue;
		path = location(args[0]);
		if (path == NULL)
		{
			perror("Not found");
			free_grid(args);
			continue;
		}
		id = fork();
		if (id == 0)
		{
			execve(path, args, environ);
			free(path);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(id, &status, 0);
			status = WEXITSTATUS(status);
			free_grid(args);
		}
	}
	return (status);
}
