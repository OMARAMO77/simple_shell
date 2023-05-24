#include "shell.h"

/**
 * _strcmp - compares two strings.
 * @s1: a string
 * @s2: a string
 * Return: The difference s1 - s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++, s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncmp  compares first n characters of two strings
 * @s1: a string
 * @s2: a string
 * @n: number of characters to compare
 *
 * Return: The difference s1 - s2
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int a = 0, diff = 0;

	while ((s1[a] && s2[a]) && a < n)
	{
		diff += s1[a] - s2[a];
		a++;
	}
	return (diff);
}

/**
 * _strcat -  function that concatenates two strings.
 * @dest: an input string
 * @src: an input string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, const char *src)
{
	char *p = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (p);
}
