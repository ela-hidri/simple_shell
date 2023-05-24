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
	write(STDIN_FILENO, "\n# ", 3);
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
	char *cmd = NULL;

	signal(SIGINT, handleexit);
	buffer = malloc(1024 * sizeof(char *));
	if (buffer == NULL)
	{
		return (1);
	}
	while (1)
	{
		cmd = NULL;
		if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO) == 1)
			write(STDIN_FILENO, "# ", 2);
		if (getline(&buffer, &len, stdin) < 0)
			break;
		splitWord(arg, strtok(buffer, "\n"));
		if (arg[0] != NULL)
		{
			if (_strcmp(arg[0], "exit") == 0)
			{
				free(buffer);
				exit(0);
			}
			 if (_strcmp(arg[0], "env") == 0)
        		{
                		print_env();
                		continue ;
        		}
        		if (arg[0] != NULL)
                		cmd = get_location(arg[0]);
        		else
                		cmd = arg[0];
			execute(cmd, arg);
			}
	}
	free(buffer);
	return (0);
}
