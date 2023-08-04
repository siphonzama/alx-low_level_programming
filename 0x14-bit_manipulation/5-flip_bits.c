#include "main.h"

/**
 * flip_bits-a function that returns the number of bits you would need to flip
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits that have been changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, count = 0;
	unsigned long int num;
	unsigned long int temp = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		num = temp >> a;
		if (num & 1)
			count++;
	}
	return (count);
}

