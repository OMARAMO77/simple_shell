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
 * main - aa
 * @argc: aa
 * @argv: aa
 * @env: aa
 *
 * Return: aa
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
			bytesRead = getline(&cmd, &buffSize, stdin);
			if (bytesRead == -1)
			{
				if (errno == EOF)
					break;
				else
					break;
			}
			if (_strcmp(cmd, "exit\n") == 0)
				exit(0);
			cmdnum++;
			if (_strncmp(cmd, "\n", 1) == 0)
				continue;
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
