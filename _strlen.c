#include "shell.h"
/**
 * _strlen: calculates the length of a string
 *
 * @str: a pointer to the string
 *
 * Return: the length of the string
 */

int _strlen(const char *str)
{
	int i = 0;
	if(str == NULL)
	{
		return 0;
	}
	while(*str)
	{
		i++;
		str++;
	}
	return(i);
}

