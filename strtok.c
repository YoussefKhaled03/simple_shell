#include "head.h"

/**
 * _strtok - function that split strings= to array of string
 * @str : string that will sp;it
 * @delim : what we will split acocording it
 * Return: new string
 */
char *_strtok(char *str, char delim)
{
	static char *cursor = NULL;
	char *start;
	
	if (str  != NULL)
		cursor = str;
	if (cursor == NULL || *cursor == '\0')
		return (NULL);
	while (*cursor == delim)
		cursor++;
	start = cursor;
	while (*cursor != '\0' && *cursor != delim)
		cursor++;
	if (*cursor == '\0')
		return (start);
	*cursor = '\0';
	cursor++;
	return (start);	
}

