#include "shell.h"
/**
 * handleexit - handles the CTRL+c
 * @sig: signal
 *
 * Return: nothing
 */
void handleexit(int sig)
{
	signal(sig, handleexit);
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

	signal(SIGINT, handleexit);
	buffer = malloc(1024 * sizeof(char *));
	if (buffer == NULL)
	{
		return (1);
	}
	while (1)
	{
		if (getline(&buffer, &len, stdin) == EOF)
		{
			write(1, "\n", 1);
			break;
		}
		splitWord(arg, strtok(buffer, "\n"));
		if (arg[0] != NULL)
		{
		if (_strcmp(arg[0], "exit") == 0)
		{
			free(buffer);
			exit(1);
		}
		execute(arg);
		}
	}
	free(buffer);
	return (0);
}
