#include "shell.h"
void exithsh(char *cmd);
void envcmd(void);
void errmsg2(char *hsh, int cmdnum, char *cmd, char *status);
/**
 * errmsg2 - aa
 * @hsh: aa
 * @cmdnum: aa
 * @cmd: aa
 * @status: aa
 *
 * Return: aa
 */

void errmsg2(char *hsh, int cmdnum, char *cmd, char *status)
{
	char num1;

	num1 = cmdnum + '0';
	write(STDERR_FILENO, hsh, _strlen(hsh));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, &num1, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, status, _strlen(status));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * envcmd - aa
 *
 * Return: aa
 */
void envcmd(void)
{
	int i = 0;
	char **env = environ;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
/**
 * exithsh - handles exit command
 * @cmd: Command string
 *
 * Return: nothing
 */
void exithsh(char *cmd)
{
	int status;

	status = _atoi(cmd + 5);
	if (status == 0)
	{
		errmsg2("./hsh", 1, "exit", cmd + 5);
		exit(2);
	}
	else
		exit(status);
}

/**
 * prompt - prompt
 *
 * Return: nothing
 */

void prompt(void)
{
	int interactive_mode;

	interactive_mode = isatty(STDIN_FILENO);
	if (interactive_mode)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		fflush(stdout);
	}
}

/**
 * main - main function
 * @argc: argument counter
 * @argv: argument vector
 * @env: aa
 *
 * Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	int i, cmdnum = 0;
	char *retcmd, *path, *cmd = NULL;
	size_t buffSize = 0;
	ssize_t bytesRead;
	char buffer[98];

/*	Register the signal handler for SIGINT*/
	signal(SIGINT, handle_sigint);
	if (argc == 1)
	{
		while (1)
		{
			prompt();
			cmdnum++;
			bytesRead = getline(&cmd, &buffSize, stdin);
			if (bytesRead == -1)
				break;
			else if (_strcmp(cmd, "env\n") == 0)
			{
				envcmd();
				continue;
			}
			else if (emp_str(cmd))
				continue;
			else if (_strcmp(cmd, "exit\n") == 0)
				break;
			else if (_strncmp(cmd, "exit ", 5) == 0)
			{
				exithsh(cmd);
				break;
			}
			retcmd = exe_cmd(cmd);
			if (retcmd != NULL)
				errmsg(argv[0], cmdnum, retcmd);
		}
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			_strncpy(buffer, argv[i], sizeof(buffer) - 1);
			buffer[sizeof(buffer) - 1] = '\0'; /* Ensure null-termination of buffer */
			if (check_path(buffer, '/'))
				path = buffer;
			else
				path = path_to(buffer);

			if (execve(path, argv + 1, env) == -1)
			{
				perror("execve2 error");
			}
		}
	}
	free(cmd);
	return (0);
}
