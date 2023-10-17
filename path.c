#include "head.h"

/**
 * location - function that will return actually path
 * @command : the path that will take
 * Return: the path
 */
char *location(char *command)
{
	char *path = _getenv("PATH"), *path_copy = NULL, *path_token = NULL, *file_path = NULL;
	unsigned int size_one, size_two;
	struct stat buffer;

	if (path == NULL)
		return (NULL);
	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);
	path_token = _strtok(path_copy, ':');
	while (path_token != NULL)
	{
		size_one = _strlen(command);
		size_two = _strlen(path_token);
		file_path = malloc(size_one + size_two + 2);
		if (file_path == NULL)
		{
		free(path_copy);
		return (NULL);
		}
	_strcpy(file_path, path_token);
	_strcat(file_path, "/");
	_strcat(file_path, command);

	if (stat(file_path, &buffer) == 0)
	{
		free(path_copy);
		return (file_path);
	}
	else 
	{
		free(file_path);
		path_token = _strtok(NULL, ':');
	}
	}
	free(path_copy);
	if (stat(command, &buffer) == 0)
	{
		return (_strdup(command));
	}
	return (NULL);
}
/**
 *_strcmp- entry point
 *
 * @s1: saged
 *@s2:sagoda
 *
 * * Return: size of @s
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t  i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != '\0' || s2[i] != '\0' ||s1[i] != s2[i])
		return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _getenv- function that return the path
 * @varname: PATH
 * Return: the path
 */
char *_getenv(char *varname)
{
	char **env;
	char *entry = NULL;

	for (env = environ; *env != NULL; env++)
	{
		entry = *env;
		if (_strncmp(entry, varname,_strlen(varname)) == 0 && entry[_strlen(varname)] == '=')
		{
			return (entry + _strlen(varname) + 1);
		}
	}
	return (NULL);
}
