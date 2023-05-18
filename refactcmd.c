#include "shell.h"
/**
 * refactcmd - refactor given command
 * @path: command to refacter
 * @path_token: Path to refacter with
 * @cmd: command to refactor with
 *
 * Return: nothing
 */
void refactcmd(char *path, char *path_token, char *cmd)
{
	int i = 0, j = 0;

	while (path_token[j])
	{
		path[i] = path_token[j];
		i++;
		j++;
	}
	path[i] = '/';
	i++;
	j = 0;
	while (cmd[j])
	{
		path[i] = cmd[j];
		i++;
		j++;
	}
	path[i] = '\0';
}
