#include "head.h"

/**
 * print_environ - print the environ
 * @environ: the array of the environ
 * Return: 0
*/

void print_environ(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		_putstring(environ[i]);
		i++;
	}
}

/**
 * _check - check for env & exit
 * @args: array of input
 * @status: saged
 * Return: 0
*/
int _check(char **args, int status)
{
	if (args[0] == "env")
		{
			print_environ(environ);
			return(1);
		}
	else if(args[0] == "exit")
		{
			free_grid(args);
			exit(status);
		}
	else
		return(0);
}
