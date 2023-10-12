#include"head.h"
/**
 * cmp - cmp
 * @st1: string 1
 * @st2: string 2
 * Return: 1 or 0
 */
int cmp(char *st1, char *st2)
{
	int i = 0;

	if (_strlen(st1) != _strlen(st2))
		return (0);
	for (i = 0; st1[i] != '\0'; i++)
	{
		if (st1[i] != st2[i])
			return (0);
	}
	return (1);
}

