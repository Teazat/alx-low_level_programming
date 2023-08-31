#include "main.h"

/**
 * print_binary - Prints the binary representation of a decimal number.
 * @n: The decimal number to be converted and printed.
 */
void print_binary(unsigned long int n)
{
	int i;
	int flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = 63; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
		{
			_putchar('0');
		}
	}
}
