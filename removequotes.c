#include "shell.h"
/**
 * remove_quotes - it removesthe quotes in a given string
 * @str: the string
 *
 * Return: the string without the quotes
 */

char *remove_quotes(const char *str)
{
	size_t len = _strlen(str);
	size_t num = 0;
	size_t i;
	size_t newlen;
	char *new_str;
	size_t j = 0;

	for (i = 0 ; i < len; i++)
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			num++;
		}
	}
	newlen = len - num + 1;
	new_str = (char *)malloc(sizeof(char) * newlen);

	for (i = 0; i < len; i++)
	{
		if (str[i] != '\"' && str[i] != '\'')
		{
			new_str[j] = str[i];
			j++;
		}
	}
	new_str[j] = '\0';
	return (new_str);
}
