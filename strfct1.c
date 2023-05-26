#include "shell.h"

/**
  * _strlen - Returns the length of a string
  * @s: String to count
  *
  * Return: String length
  */
int _strlen(const char *s)
{
	int a, len = 0;

	for (a = 0; s[a] != '\0'; a++)
		len++;
	return (len);
}

/**
  * _strcpy - Copies a string
  * @dest: Destination value
  * @src: Source value
  *
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i++] = '\0';
	return (dest);
}

/**
 * _strncpy - a function that copys the strings.
 * @dest: a string
 * @src: a string
 * @n: an integer
 * Return: A pointer to the resulting string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a = 0, b = 0;

	while (src[b])
		b++;
	while (a < n && src[a])
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}

/**
 * empty - aa
 * @ch: aa
 *
 * Return: aa
 */

int empty(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n')
	{
		return (1);
	}
	return (0);
}

/**
 * emp_str - aa
 * @cmd: aa
 *
 * Return: aa
 */

int emp_str(char *cmd)
{
	int mul = 1, a = 0, ret;

	while (cmd[a])
	{
		ret = empty(cmd[a]);
		mul *= ret;
		a++;
	}
	return (mul);
}
