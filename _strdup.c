#include "shell.h"

/**
 * _strdup - create a duplicate copy of a string
 * @str: the string to be copied
 *
 * Return: q pointer to the new string
 */

char *_strdup(const char *str)
{
	size_t i;
	char *new_str;
	size_t length = _strlen(str) + 1;

	if (str == NULL)
	{
		return (NULL);
	}
	new_str = (char *)malloc(length * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		new_str[i] = str[i];

	return (new_str);
}
