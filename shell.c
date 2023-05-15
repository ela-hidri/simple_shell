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
	pid_t child;

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

		child = fork();
		if (child < 0)
		{
			perror("Error:");
			return (1);
		}
		wait(&status);
		if (child == 0)
		{
			splitWord(arg, strtok(buffer, "\n"));
			if (execve(arg[0], arg, NULL) < 1)
			{
				perror("Error:");
				return (1);
			}
		}
	}
	free(buffer);
	return (0);
}
