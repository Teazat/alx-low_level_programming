#include "main.h"

/**
 * get_bit - Retrieves value of a bit at a specific index in a decimal.
 * @n: The decimal number from which to retrieve the bit.
 * @index: The index of the bit to retrieve (0-based).
 *
 * Return: The value of the bit at the specified index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	return ((n >> index) & 1);
}
