#include "shell.h"
/**
 * execute - handle command execution
 * @arg: array of command
 * @cmd: command
 * @av: name of file
 *
 * Return: nothing
 */
void execute(char *cmd, char *arg[], char *av)
{
	int status;
	pid_t child;
	int r = 0;

	if (cmd && access(cmd, F_OK | X_OK) == 0)
	{
		child = fork();
		if (child < 0)
		{
			perror(cmd);
		}
		if (child == 0)
		{
			if (execve(cmd, arg, environ) < 0)
			{
				perror(av);
				free(cmd);
			}
		}
		else
		{
			wait(&status);
		}
	}
	else
	{
		if (errno == EACCES)
			r = 126;
		free(cmd);
		perror(av);
		_exit(r);
	}
}
