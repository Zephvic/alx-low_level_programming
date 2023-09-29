#include "main.h"
/**
 *  * _strlen_recursion - function that Returns the length of a string.
 * @s: The string to be measured.*
 * Return: The length 
 */
int _strlen_recursion(char *s)
{
	int length = 0;

	if (*s)
	{
		length++;
		length += _strlen_recursion(s + 1);
	}
	return (length);
}
