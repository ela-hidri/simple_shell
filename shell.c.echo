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
<<<<<<< HEAD
	int numArgs;
        char** cmdargs;
        int i;
        char* argwithoutquotes;
       

	/*signal(SIGINT, haandleexit);*/
=======

	signal(SIGINT, handleexit);
>>>>>>> 80cf584e032ef5a41f09fb71a80298c53aa2e6ae
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
		if (arg[0] != NULL)
		{
		if (_strcmp(arg[0], "exit") == 0)
		{
			free(buffer);
			exit(1);
<<<<<<< HEAD
                }
		else if (_strcmp(arg[0], "echo") == 0)
		{	
			
			numArgs = 0;
                        cmdargs = malloc((sizeof(char*)*2));
                        cmdargs[0] = arg[0];
                        numArgs++;
                        for ( i = 1; arg[i] != NULL; i++)
                        {
                                argwithoutquotes = strdup(remove_quotes(arg[i]));
                                cmdargs = realloc(cmdargs, (sizeof(char*) * (numArgs + 2)));
                                cmdargs[numArgs] = argwithoutquotes;
                                numArgs++;
                        }
			cmdargs[numArgs] = NULL;
			execute(cmdargs);
                        
                       
		} 
		else
			execute(arg);
		} 
	} 
=======
		}
		execute(arg);
		}
	}
>>>>>>> 80cf584e032ef5a41f09fb71a80298c53aa2e6ae
	free(buffer);
	return (0);
}
