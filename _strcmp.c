#include "shell.h"
/**
 * _strcmp: compare two strings
 *
 * @str1:a pointer to the first string 
 * @str2: pointer to the second string
 *
 * Return: 0 it they are equal -1  otherwise
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (-1);

		}
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0);
	}

	return (-1);

}

