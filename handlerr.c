#include "shell.h"

/**
  * extcmd - aa
  * @cmd: aa
  * @bytesRead: aa
  *
  * Return: aa
  */
int extcmd(char *cmd, ssize_t bytesRead)
{
	int status;
	
	if (cmd[bytesRead - 1] == '\n')
		cmd[bytesRead - 1] = '\0';

	if (_strcmp(cmd, "exit") == 0)
		return (0);

	if (_strncmp(cmd, "exit ", 5) == 0)
	{
		status = _atoi(cmd + 5);
		return (status);
	}
	
	return (0);
}
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
 * handle_sigint - handle_sigint
 *
 * Return: nothing
 */
void handle_sigint(void)
{
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
	fflush(stdout);
	contloop = 1;
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
	write(STDOUT_FILENO, hsh, strlen(hsh));
	write(STDOUT_FILENO, ": ", 2);
	_printnum(cmdnum);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, ": not found\n", 12);

}
