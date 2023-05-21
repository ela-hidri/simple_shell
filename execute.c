#include "shell.h"
/**
 * execute - handle command execution
 * @arg: array of command
 *
 * Return: nothing
 */
void execute(char *arg[])
{
	int status;
	pid_t child;
	char *cmd;

	if (arg[0] != NULL)
		cmd = get_location(arg[0]);
	else
		cmd = arg[0];
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
		exit(1);
	}
	wait(&status);
	if (child == 0)
	{
<<<<<<< HEAD
		if(_strcmp(arg[0], "env") == 0 )
=======
		if (_strcmp(arg[0], "env") == 0)
>>>>>>> 80cf584e032ef5a41f09fb71a80298c53aa2e6ae
		{
			print_env();
		}

		else
		{
			if (execve(cmd, arg, environ) < 1)
			{
				perror("Error:");
				exit(1);
			}
		}
	}
	free(cmd);
}

