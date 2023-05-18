#include "shell.h"
/**
 * execute - handle command execution
 * @cmd: command typed
 *
 * Return: nothing
 */
void execute(char *arg[])
{
	int status;
	pid_t child;
	char *cmd;
	
	cmd = get_location(arg[0]);
	if (cmd != NULL)
	{
		child = fork();
	}
	else
	{
		perror("Error:");
	}
	if (child < 0)
	{
		perror("Error:");
		exit (1);
	}
	wait(&status);
	if (child == 0)
	{
		if(strcmp(arg[0], "env") == 0 )
		{
			print_env();
		}
		else
		{
			if (execve(cmd, arg, environ) < 1)
			{
				perror("Error:");
				exit (1);
			}
		}
	}
}

