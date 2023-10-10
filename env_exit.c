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
		_putchar('\n');
		i++;
	}
}

/**
 * _check - check for env & exit
 * @args: array of input
 * @status: saged
 * Return: 0
*/
int _check(char *arg, int status)
{
	char *ev = "env";
	char *ex = "exit";

	if (arg == ev)
		{
			print_environ(environ);
			printf("looooooooooooooool");
			return(1);
		}
	else if(arg == ex)
		{
			free_grid(args);
			exit(status);
		}
	else
		return(0);
}
