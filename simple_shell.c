#include "head.h"

/**
 * main - main finction
 * Descreption: main function of our simple shell
 * Return: 0 success
 */

int main(void)
{
	char **args = NULL, *path = NULL, *command;
	int status = 0;
	int er = 0;
	int a = isatty(STDIN_FILENO);

	while (1)
	{
		er++;
		if (a)
			_putstring("$ ");
		command = malloc(5000000);
		if (fgets(command, 5000000, stdin) == NULL)
		{
			free(command);
				break;
		}
		if (command[_strlen(command) - 1] == '\n')
			command[_strlen(command) - 1] = '\0';
		if (_strlen(command) == 0)
		{
			free(command);
			continue;
		}
		args = fill(command);
		if (_check(args, status, command))
		{
			free_grid(args), free(command);
			continue;
		}
		path = location(args[0]);
		if (path == NULL)
		{
			errors(er, command);
			free_grid(args);
			continue;
		}
		free(args[0]), args[0] = path, free(command);
		status = _fork(status, path, args, er);
	}
	return (status);
}
/**
 *errors - print errors
 *@er: integer
 *@command: the command
 *Return: null
 */
void errors(int er, char *command)
{
	char *erro = handle_int(er);

	write(2, "./hsh: ", 7);
	write(2, erro, _strlen(erro));
	write(2, ": ", 2);
	write(2, command,  _strlen(command));
	write(2, ": not found\n", _strlen(": not found\n"));
	free(command);
	free(erro);
}
