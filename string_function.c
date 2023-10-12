#include "head.h"

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 *_atoi- entry point
 *
 * @s: sagoda
 *
 *
 * * Return: size of @s
 */

int _atoi(char *s)
{
	int i = 0;
	unsigned int j = 0;
	int two = 1;
	int z = 1;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			z *= -1;

		while (s[i] >= '0' && s[i] <= '9')
		{
			two = 0;
			j *= 10;
			j += s[i] - '0';
			i++;
			if (s[i] == '\0')
			{
				j *= z;
				return (j);
			}
		}
		j *= z;
		if (two == 0)
			return (j);
		i++;
	}
	return (j);
}
/**
 * _strlen- entry point
 *
 * @s: saged
 *
 *
 * * Return: size of @s
 */

int _strlen(char *s)
{
	int p;

	for (p = 0; *s != '\0'; s++)
		p++;
	return (p);
}
