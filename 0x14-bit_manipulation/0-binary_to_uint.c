#include "main.h"

/**
 * binary_to_uint-a function that converts a binary number to an unsigned int.
 * @b: is a pointer that points to a binary number
 * Return: the new number
 */

unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int new_val  = 0;

	if (!b)
		return (0);

	for (a = 0; b[a]; a++)
	{

		if (b[a] < '0' || b[a] > '1')
			return (0);
		new_val = 2 * new_val + (b[a] - '0');
	}
	return (new_val);
}
