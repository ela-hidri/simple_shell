#include "shell.h"
/**
 * get_location - get command path
 * @cmd: command typed
 *
 * Return: path
 */
char *get_location(char *cmd)
{
	char *path, *cp_path, *token, *cmd_path = NULL;
	struct stat st;
	char *suspect = NULL;

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
			suspect = _strdup(token);
			cmd_path = malloc((_strlen(cmd) + _strlen(suspect) + 2) * sizeof(char));
			if (cmd_path == NULL)
				exit(1);
			refactcmd(cmd_path, suspect, cmd);
			free(suspect);
			if (stat(cmd_path, &st) == 0)
			{
				free(cp_path);
				return (cmd_path);
			}
			free(cmd_path);
			cmd_path = NULL;
			token = strtok(NULL, ":");
		}
		free(cp_path);
	}
return (NULL);
}
