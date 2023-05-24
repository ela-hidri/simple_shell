#include "shell.h"
/**
 * get_location - get command path
 * @cmd: command typed
 *
 * Return: path
 */
char *get_location(char *cmd)
{
	char *path, *cp_path, *token, *cmd_path;
	struct stat st;

	if (stat(cmd, &st) == 0)
	{
		return (cmd);
	}
	path = _getenv("PATH");
	if (path != NULL)
	{
		cp_path = _strdup(path);
		token = strtok(cp_path, ":");
		while (token != NULL)
		{
			cmd_path = malloc((_strlen(cmd) + _strlen(token) + 2) * sizeof(char));
			if (cmd_path == NULL)
				exit(1);
			refactcmd(cmd_path, token, cmd);
			if (stat(cmd_path, &st) == 0)
			{
				free(cp_path);
				return (cmd_path);
			}
			else
			{
				free(cmd_path);
				token = strtok(NULL, ":");
			}
		}
		free(cp_path);
	}
return (NULL);
}
