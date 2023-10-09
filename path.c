#include "head.h"

/**
 * location - function that will return actually path
 * @command : the path that will take
 * Return: the path
 */
char *location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	unsigned int size_one, size_two;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		size_one = _strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			size_two = _strlen(path_token);
			file_path = malloc(size_one + size_two + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
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

int _strcmp(char *s1, char *s2)
{
	for (; (*s1 != '\0' && *s2 != '\0') && (*s1 == *s2); s1++, s2++)
		;
	if (*s1 == *s2)
	{
		return (0);
	}
	return (*s1 - *s2);
}
/**
 * _getenv- function that return the path
 * @varname: PATH
 * Return: the path
 */
char *_getenv(char *varname)
{
	char **env;
	char *entry;

	for (env = environ; *env != NULL; env++)
	{
		entry = *env;
		if (_strcmp(entry, varname) == 0 && entry[_strlen(varname)] == '=')
		{
			return (entry + _strlen(varname) + 1);
		}
	}
	return (NULL);
}
