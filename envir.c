#include "shell.h"
/**
 * _getenv - get envirmantal variable path
 * @val: variable
 *
 * Return: pointer to path else NULL
 */
char *_getenv(char *val)
{
	char **env = environ;
	char *path;

	while (*env)
	{
		if (strncmp(*env, val, _strlen(val)) == 0)
		{
			path = *env + _strlen(val) + 1;
			return (path);
		}
		env++;
	}
	return (NULL);
}
/**
 * print_env - print all enviroment Values
 *
 * Return: nothing
 */
void print_env(void)
{
	int i = 0;
	char **env = environ;

	while (environ[i])
	{
		write(STDOUT_FILENO, (const void *)env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
		i++;
	}
}
