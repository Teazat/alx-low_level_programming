#include "main.h"

/**
 * clear_bit - clears the value of a bit at a given index (sets to 0)
 * @n: pointer to the number to modify
 * @index: index of the bit to clear
 *
 * Return: 1 if successful, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}
