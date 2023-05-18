#include "shell.h"
/**
 * handleExit - handles the CTRL+c
 * @sig: signal
 *
 * Return: nothing
 */
void handleExit(int sig)
{
	signal(sig, handleExit);
}
/**
 * main - UNIX command line interpreter
 * @argv: argument vector
 * @argc: argument count
 * @env: environment argument
 *
 *
 * Return: success (alwayas)
 */
int main(__attribute__ ((unused)) int argc,
		__attribute__ ((unused))char **argv,
		__attribute__ ((unused)) char **env)
{
	char *buffer;
	size_t len = 1024;
	char *arg[50];
	int status;
	char *token;
	pid_t child;
	int i;
	char *cmd;

	/*signal(SIGINT, handleExit);*/
	buffer = malloc(1024 * sizeof(char *));
	if (buffer == NULL)
	{
		return (1);
	}
	while (1)
	{
		write(1, "($) ", 4);
		if (getline(&buffer, &len, stdin) == EOF)
		{
			write(1, "\n", 1);
			break;
		}
		 splitWord(arg, strtok(buffer, "\n"));
                cmd = get_location(arg[0]);
                if (cmd != NULL)
                {
                        child = fork();
                }
                else
                {
                        perror("Error:");
                }
		token = strtok(buffer, " ");
		if (strcmp(token, "exit\n")==0)
		{
			free(buffer);
			exit(1);
		}
		if (child < 0)
		{
			perror("Error:");
			return (1);
		}
		wait(&status);
		if (child == 0)
		{
			if(strcmp(arg[0], "env") == 0 )
			{
				i = 0;
				while(env[i])
				{
					printf("%s\n", env[i]);
					i++;
				}
			}
			else if(execve(arg[0], arg, NULL) < 1)
			{
				perror("Error:");
				return (1);
			}
		}
	}
	free(buffer);
	return (0);
}
