#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if b contains chars not 0 or 1 or if
 * b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	const char *ptr = b;
	unsigned int dec_val = 0;

	if (!ptr)
		return (0);

	while (*ptr)
	{
		if (*ptr != '0' && *ptr != '1')
			return (0);
		dec_val = (dec_val << 1) | (*ptr - '0');
		ptr++;
	}

	return (dec_val);
}
