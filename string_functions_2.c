#include "head.h"

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
/**
 * _putstring- function print string
 * @s: string that will print
 * Return: size of string
 */

int _putstring(char *s)
{
	int i;

	if (!s)
		return(0);
	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return (i);
}

/**
 *_strdup- entry point
 *
 * @str: saged
 * * Return: size of @s
 */

char *_strdup(char *str)
{
	unsigned int i = 0, j = 0;
	char *c = NULL;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		i++;
	}
	c = malloc(i+1);
	if (c == NULL)
		return (NULL);
	_strcpy(c,str);
	return (c);
}
/**
 * _putchar- print char
 * @c: char that will print
 * Return: 0 success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
