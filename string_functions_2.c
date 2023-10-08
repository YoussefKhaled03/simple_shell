#include "head.h"
/**
 *_strncpy- entry point
 *
 * @dest: saged
 *@src:sagoda
 *@n:aboelsagage
 * * Return: size of @s
 */

char *_strncpy(char *dest, char *src, int n)
{
	int j;

	for (j = 0 ; j < n && src[j] != '\0' ; j++)
	{
		dest[j] = src[j];
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
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
		return (NULL);
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
	char *c;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		i++;
	}
	c = malloc((i + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	for (; j < i ; j++)
		c[j] = str[j];
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
