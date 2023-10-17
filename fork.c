#include "head.h"

/**
 * _fork - function that handle fork
 * @status: status that will return
 * Return: status
*/
int _fork (int status, char *path,  char **args, int err)
{
	char *in;
	pid_t id = fork();
	if (id == 0)
	{
		execve(path, args, environ);
		in = handle_int(err);
		write(2, "./hsh: ", 7);
		write(2, in, _strlen(in));
		write(2, ": ", 2);
		write(2, path, _strlen(path));
		write(2, ": No such file or directory\n", 28);
		free_grid(args);
		free(in);
		exit(127);
	}
	else
	{
		waitpid(id, &status, 0);
		status = WEXITSTATUS(status);
		free_grid(args);
	}
	return (status);
}
/**
 * error - return error massege
 * @str: string that will error
 * @n: number of error
 * Return: string that will eccure
*/
char *error(char *str, int n)
{
	return (_strcat(str,handle_int(n)));
}
/**
 * handle_int - function will convert int to string
 * @x: the integer number
 * Return: the number in string
 */
char *handle_int(int x)
{
	char v[19];
	char  *new;
	int i = 0, n = 0;

	while (x)
	{
		v[i] = x % 10 + '0';
		i++;
		x /= 10;
	}
	new = malloc(i);
	i--;
	while (i >= 0)
	{
		new[n] = v[i];
		i--;
		n++;
	}
	new[n] = '\0';
	return (new);
}
