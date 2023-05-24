#include "shell.h"
/**
 * execute - handle command execution
 * @arg: array of command
 *
 * Return: nothing
 */
void execute(char *cmd, char *arg[])
{
	int status;
	pid_t child;
	
	if (cmd && access(cmd, F_OK | X_OK) == 0)
	{
		child = fork();
		if (child < 0)
		{
			perror(cmd);
		}
		if (child == 0)
		{
			execve(cmd, arg, environ);
			perror(cmd);
			free(cmd);
		}
		else
		{
			wait(&status);
		}
	}
	else
	{
		free(cmd);
		perror(cmd);
	}
}
