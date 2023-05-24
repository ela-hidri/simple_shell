#include "shell.h"
/**
 * _strncmp - it compare two string at most n characters between
 * the two strings
 * @str1: pointer to the first string
 * @str2: pointer to the second string
 * @n: the number n
 *
 * Return: 0 if they are equal in the first n characters
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
		else if (str1[i] == '\0' || str2[i] == '\0')
			return (0);
	}
	return (0);
}
