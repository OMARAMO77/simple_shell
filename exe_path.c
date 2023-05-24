#include "shell.h"

/**
 * _getenv - aa
 * @name: aa
 *
 * Return: aa
 */

char *_getenv(const char *name)
{
	size_t len;
	char **env;

	env = environ;
	if (name == NULL || environ == NULL)
		return (NULL);

	len = _strlen(name);
	while (*env)
	{
		if (_strncmp(name, *env, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);  /* Return the value part after the '=' character*/
		}
		env++;
	}
	return (NULL);  /* Environment variable not found*/
}

/**
 * check_path - aa
 * @str: aa
 * @ch: aa
 *
 * Return: 1 on success, 0 on failure.
 */

int check_path(const char *str, char ch)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (str[a] == ch)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * exe_cmd - aa
 * @cmd: aa
 *
 * Return: a
 */

char *exe_cmd(char *cmd)
{
	pid_t c_pid;
	char *tok, *path;
	char *args[14];
	int status, argcnt = 0;
	char **env;

	env = environ;
	tok = strtok(cmd, " \n");
	while (tok != NULL && argcnt < 14)
	{
		args[argcnt++] = tok;
		tok = strtok(NULL, " \n");
	}
	args[argcnt] = NULL;
	if (check_path(args[0], '/'))
		path = args[0];
	else
		path = path_to(args[0]);

	if (access(path, X_OK) == 0)
	{
		c_pid = fork();
		if (c_pid == -1)
		{
			perror("fork error");
			return (NULL);
		}
		else if (c_pid == 0)
		{
			execve(path, args, env);
			perror("execve error");
		}
		else
			wait(&status);
	}
	else
	{
		return (args[0]);
	}
	return (NULL);	/* note that i returned NULL here! */
}

/**
  * path_to - aa
  * @filename: aa
  *
  * Return: aa
  */

char *path_to(const char *filename)
{
	char *path_env, *path, *token, *file_path = NULL;
	int path_length;

	path_env = _getenv("PATH");
	if (path_env == NULL)
	{
		perror("PATH environment variable not found.\n");
		return (NULL);
	}
	path = malloc(strlen(path_env) + 1);
	if (path == NULL)
	{
		perror("Memory allocation error.\n");
		return (NULL);
	}
	_strcpy(path, path_env);
	token = strtok(path, ":");
	while (token != NULL)
	{
		path_length = strlen(token) + strlen(filename) + 2; /* +2 for '/' and '\0' */
		file_path = malloc(path_length);
		if (file_path == NULL)
		{
			perror("Memory allocation error.\n");
			free(path);
			return (NULL);
		}
		_strcpy(file_path, token);
		_strcat(file_path, "/");
		_strcat(file_path, filename);
		if (access(file_path, X_OK) == 0)
			break;
		free(file_path);
		file_path = NULL;
		token = strtok(NULL, ":");
	}
	if (file_path == NULL)
		return (NULL);
	free(path);
	return (file_path);
}
