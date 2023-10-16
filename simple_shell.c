#include "head.h"

/**
 * main - main finction
 * Descreption: main function of our simple shell
 * Return: 0 success
 */

int main(void)
{
	char command [1024];
	char **args = NULL, *path = NULL;
	int status = 0;
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
		if (_strlen(command)== 0)
		{
				continue;
		}
		args = fill(command);
		if (_check(args, status))
		{
			free_grid(args);
			continue;
		}
		path = location(args[0]);
		if (path == NULL)
		{
			perror("Not found");
			free_grid(args);
			continue;
		}
		free(args[0]);
		args[0]= path;
		status = _fork(status,path,args);
	}
	free_grid(args);
	return (status);
}
