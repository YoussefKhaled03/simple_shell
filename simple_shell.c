#include "head.h"

/**
 * main - main finction
 * Descreption: main function of our simple shell
 * Return: 0 success
 */

int main(void)
{
	char *command;
      	//char **args = NULL, *path = NULL;
	int status = 0;
	pid_t id;

	while (1)
	{
		_putstring("$ ");
		fflush(stdin);
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		if (command[_strlen(command) - 1] == '\n')
			command[_strlen(command) - 1] = '\0';
		args = fill(command);
		if (_check(args[0], status))
			continue;
		path = location(args[0]);
		if (path == NULL)
		{
			perror("Not found");
			free_grid(args);
			continue;
		}
		free(args[0]);
		args[0]= path;
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
