#include "shell.h"
/**
 * checkcmd: check the command
 * @args: the command
 *
 * Return -1 if the command doesn't exist
 */
/*int checkcmd(**arg)
{
	char *cmd[] = {"exit", "env", "cd", NULL};
	int i = 0 ;
	while(cmd[i] != NULL)
	{
		if(_strcmp(cmd[i], arg[0]) == 0)
			return (1);
		i++;
	}
	return (-1);
}
int chechexit(char **args)
{
	if(checkcmd(args) == 1)
	{
		return (3);
	}
	if(access(arg[0], X_OK) == 0)
		return (1);*/

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
