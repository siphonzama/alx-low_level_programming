#include "main.h"

/**
 * get_bit-brings the bit at an index as a decimal number
 * @n: number to search
 * @index: index for the bit
 *
 * Return: the value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{

	int bit;

	if (index > 36)
		return (-1);


	bit = (n >> index) & 1;

	return (bit);

}
