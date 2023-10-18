#include "head.h"

/**
 *free_grid- entry point
 *@grid :sagoda
 * * Return: size of @s
 */

void free_grid(char **grid)
{
	int i = 0;

	if (!grid)
		return;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
/**
 * fill - function to fill arg array with command
 * @command : the commant
 * Return: array of string
*/
char **fill(char *command)
{
	int i = 0;
	char *s = NULL;
	char dil = ' ';
	char **arr = malloc(sizeof(char *) * 500000);

	s = _strtok(command, dil);
	arr[0] = malloc(sizeof(char) * _strlen(s) + 5);
	_strcpy(arr[0], s);
	i++;
	while ((s = _strtok(NULL, dil)))
	{
		arr[i] = malloc(sizeof(char) * _strlen(s) + 5);
		_strcpy(arr[i], s);
		i++;
	}
	arr[i] = NULL;
	free(s);
	return (arr);
}
