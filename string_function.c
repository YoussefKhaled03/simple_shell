#include "head.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_strncat- entry point
 *
 * @dest: saged
 *@src:sagoda
 *@n:aboelsagage
 * * Return: size of @s
 */

char *_strncat(char *dest, char *src, int n)
{
	int j;
	int i = 0;

	while (dest[i])
	{
		i++;
	}
	for (j = 0 ; src[j] && j < n ; j++)
	{
		dest[i++] = src[j];
	}
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
