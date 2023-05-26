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
 * handle_sigint - handle_sigint
 *
 * Return: nothing
 */

void handle_sigint(void)
{
	_putchar(10);
	exit(0);
}

/**
 * errmsg - aa
 * @hsh: aa
 * @cmdnum: aa
 * @cmd: aa
 *
 * Return: aa
 */

void errmsg(char *hsh, int cmdnum, char *cmd)
{
	char num1, num2, num3;

	write(STDERR_FILENO, hsh, _strlen(hsh));
	write(STDERR_FILENO, ": ", 2);
	if (cmdnum < 10)
	{
		num1 = cmdnum + '0';
		write(STDERR_FILENO, &num1, 1);
	}
	else if (cmdnum > 9 && cmdnum < 100)
	{
		num1 = (cmdnum / 10) + '0';
		num2 = (cmdnum % 10) + '0';
		write(STDERR_FILENO, &num1, 1);
		write(STDERR_FILENO, &num2, 1);
	}
	else if (cmdnum > 99)
	{
		num1 = (cmdnum / 100) + '0';
		num2 = ((cmdnum / 10) % 10) + '0';
		num3 = (cmdnum % 10) + '0';
		write(STDERR_FILENO, &num1, 1);
		write(STDERR_FILENO, &num2, 1);
		write(STDERR_FILENO, &num3, 1);
	}

	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);

}
