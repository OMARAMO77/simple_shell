#include "shell.h"

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
  * _printnum - Prints an integer
  * @n: Number to print
  *
  * Return: Nothing
  */

void _printnum(int n)
{
	unsigned int x;

	x = n;
	if (x / 10)
		_printnum(n / 10);
	_putchar(n % 10 + '0');
}

/**
 * handle_sigint - handle_ sigint
 *
 * Return: nothing
 */

void handle_sigint(void)
{
	_putchar(10);
	exit(0);
}

/**
 * errmsg - read error msg
 * @hsh: aa
 * @cmdnum: aa
 * @cmd: aa
 *
 * Return: aa
 */

void errmsg(char *hsh, int cmdnum, char *cmd)
{
	write(STDOUT_FILENO, hsh, strlen(hsh));
	write(STDOUT_FILENO, ": ", 2);
	_printnum(cmdnum);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, ": not found\n", 12);

}
