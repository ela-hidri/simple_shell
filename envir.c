#include "shell.h"
/**
 * _getenv - get envirmantal variable path
 * @val: variable
 *
 * Return: pointer to path else NULL
 */
char **_getenv(char *val)
{
	int i = 0;

	while (environ[i])
	{
		if (strcmp(environ[i], val) == 0)
		{
			return (&environ[i]);
		}
		i++;
	}
	return (NULL);
}
/**
 * printf_env - print all enviroment Values
 *
 * Return: nothing
 */
void print_env()
{
	int i = 0;

	while(environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
