#include "main.h"

/**
 * print_binary-a function that prints the binary representation of a number.
 * @n: the binary print in a number
 *
 */

void print_binary(unsigned long int n)
{
	int a, count = 0;
	unsigned long int num;

	for (a = 63; a >= 0; a--)
	{
		num = n >> a;

		if (num & 1)
		{

			putchar('1');
			count++;
		}

		else if (count)
			putchar('0');

	}
	if (!count)
		putchar ('0');
}
