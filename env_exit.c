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
 * @arg: array of input
 * @status: saged
 * Return: 0
*/
int _check(char **arg, int status, char* command)
{
	char *s1 = "env";
	char *s2 = "exit";

	if (compare_string(s1, arg[0]))
	{
		print_environ(environ);
		return (1);
	}
	else if (compare_string(s2, arg[0]))
	{
		free_grid(arg);
		free(command);
		exit(status);
	}
	else
		return (0);
}
/**
 * compare_string- function compare two string
 * @s1: first string
 * @s2: second string
 * Return: 1 or 0
 */
int compare_string(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	if (s1[i] != '\0' || s2[i] != '\0')
		return (0);
	return (1);
}
