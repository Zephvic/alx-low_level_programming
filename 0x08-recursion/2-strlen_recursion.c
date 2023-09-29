#include "main.h"
/**
 * _strlen_recursion - function that Returns the length of a string.
 * @s: The string
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	int longit = 0;

	if (*s)
	{
		longit++;
		longit += _strlen_recursion(s + 1);
	}

	return (longit);
}
