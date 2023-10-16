#include "head.h"

/**
 * _fork - function that handle fork
 * @status: status that will return
 * Return: status
*/
int _fork (int status, char *path,  char **args)
{
	pid_t id = fork();
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
	return (status);
}
