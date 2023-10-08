#include "head.h"

/**
 *free_grid- entry point
 *@grid :sagoda
 * @height: saged
 * * Return: size of @s
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height ; i++)
		free(grid[i]);
	free(grid);
}
/**
 * fill - function to fill arg array with command
 * @command : the commant
 * Return: array of string
*/
char **fill(char *command)
{
	char *s = NULL;
	char **arr = malloc(sizeof(char *) * 1024);

	s = strtok(command, " ");
	arr[0] = malloc(sizeof(char) * _strlen(s) + 1);
	_strcpy(arr[0], s);
	i++;
	while ((s = strtok(NULL, " ")))
	{
		arr[i] = malloc(sizeof(char) * _strlen(s) + 1);
		_strcpy(arr[i], s);
		i++;
	}
	arr[i] = NULL;
	free(s);
	return (arr);
}
