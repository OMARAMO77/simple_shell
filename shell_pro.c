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
			if (_strncmp(cmd, "exit ", 5) == 0)
			{
				status = _atoi(cmd + 5);
				exit(status);
			}

			cmdnum++;
			if (_strncmp(cmd, "\n", 1) == 0)
				continue;
			retcmd = exe_cmd(cmd);
			if (retcmd != NULL)
				errmsg(argv[0], cmdnum, retcmd);
		}
	}
	free(cmd);
	return (0);
}
