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
	char *answer = NULL;
	int i = 0;
	
	if (str  != NULL)
		cursor = str;
	if (cursor == NULL)
		return NULL;
	while (str[i] != '\0')
	{
		if (cursor[i] != delim)
			answer[i] = cursor[i];
		else
		{
			answer[i] = '\0';
			cursor = cursor + i + 1;
			return (answer);
		}
		i++;
	}
	answer[i] = '\0';
	cursor = NULL;
	return (answer);	
}

