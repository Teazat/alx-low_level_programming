#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int i;
	unsigned long int current;
	int has_started = 0;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			_putchar('1');
			has_started = 1;
		}
		else if (has_started)
		{
			_putchar('0');
		}
	}
	if (!has_started)
		_putchar('0');
}
