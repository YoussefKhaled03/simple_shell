#include "head.h"

/**
 * main - main finction
 * Descreption: main function of our simple shell
 * Return: 0 success
 */

int main(void)
{
	char command[50000];
	char **args = NULL, *path = NULL, *erro = NULL;
	int status = 0;
	int er = 0;

	while (1)
	{
		er++;
		_putstring("$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
			break;
		if (command[_strlen(command) - 1] == '\n')
			command[_strlen(command) - 1] = '\0';
		if (_strlen(command) == 0)
			continue;
		args = fill(command);
		if (_check(args, status))
		{
			free_grid(args);
			continue;
		}
		path = location(args[0]);
		if (path == NULL)
		{
			erro = handle_int(er);
			write(2, "./hsh: ", 7);
			write(2, erro, _strlen(erro));
			write(2, ": ", 2);
			write(2, command,  _strlen(command));
			write(2, ": not found\n", _strlen(": not found\n"));
			free_grid(args);
			free(erro);
			continue;
		}
		free(args[0]);
		args[0] = path;
		status = _fork(status, path, args, er);
	}
	free_grid(args);
	return (status);
}
