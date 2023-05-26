#include "shell.h"

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
	int i, status, cmdnum = 0;
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
			{
				if (errno == EOF)
					break;
				else
					break;
			}
			else if (_strcmp(cmd, "env\n") == 0)
			{
				i = 0;
				while (env[i] != NULL)
				{
					write(STDOUT_FILENO, env[i], _strlen(env[i]));
					write(STDOUT_FILENO, "\n", 1);
					i++;
				}
				continue;
			}
			if (emp_str(cmd))
				continue;
			else if (_strcmp(cmd, "exit\n") == 0)
				exit(0);
			else if (_strncmp(cmd, "exit ", 5) == 0)
			{
				status = _atoi(cmd + 5);
				exit(status);
			}
			else if ((retcmd = exe_cmd(cmd)) != NULL)
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
