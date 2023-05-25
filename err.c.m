#include "shell.h"
/**
 * err - write error
 * @av: envirment
 * @ac: agr
 * @cmd: command
 *
 * Return: nothing
 */
void err(char *ac, char *av, char *cmd)
{
	char *error = NULL, *msg = "not found\n", *sep = ": ";
	int i = 0, j = 0;

	error = malloc(sizeof(char) * (
				_strlen(ac) + 
				_strlen(cmd) +
				_strlen(av) +
				_strlen(sep) * 2 +
				_strlen(msg)));
	while (av[j])
	{
		error[i] = av[j];
		i++;
		j++;
	}
	for (j = 0; sep[j]; j++)
	{
		error[i] = sep[j];
		i++;
	}
	while (ac[j])
        {
                error[i] = ac[j];
                i++;
                j++;
        }
	for (j = 0; cmd[j]; j++)
	{
		error[i] = cmd[j];
		i++;
		j++;
	}
	for (j = 0; sep[j]; j++)
        {
                error[i] = sep[j];
                i++;
        }
	for (j = 0; msg[j]; j++)
	{
		error[i] = msg[j];
		i++;
	}
	write(STDERR_FILENO, error, _strlen(error));
	free(error);
}
