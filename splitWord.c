#include <stddef.h>
#include "shell.h"
/**
 * splitWord - split word separated by a space
 * @str: word
 * @arg: array to store splitted word
 *
 * Return: nothing
 */
void splitWord(char **arg, char *str)
{
	int i = 0;
	char *token;

	token = strtok(str, " ");
	while (token != NULL && *token != '\0')
	{
		arg[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	arg[i] = NULL;
}
