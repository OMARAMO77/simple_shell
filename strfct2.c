#include "shell.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * Return: A integer
 */
int _atoi(char *s)
{
	int n = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[n])
	{
		if (s[n] == 45)
		{
			min *= -1;
		}

		while (s[n] >= 48 && s[n] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[n] - '0');
			n++;
		}

		if (isi == 1)
		{
			break;
		}

		n++;
	}

	ni *= min;
	return (ni);
}

/**
 * _strcmp - a function that compares two strings.
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
 * _strncmp - compares the first n characters of two strings
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
 * _strcat - a function that concatenates two strings.
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
