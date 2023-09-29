#include "main.h"

/**
 * _putchar - writes a character to the stdout of c
 * @c: the characcter that will be print
 *
 * Return: on success 1.
 * error, -1 is returned
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
