#include "main.h"

/**
 * flip_bits - Counts num of bits to change to get from one num to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits to change.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int exclusive = n ^ m;
	unsigned int count = 0;

	while (exclusive)
	{
		count += exclusive & 1;
		exclusive >>= 1;
	}

	return (count);
}
