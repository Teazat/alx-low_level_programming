#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	const char *ptr = b;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	while (*ptr)
	{
		if (*ptr != '0' && *ptr != '1')
			return (0);

		if (dec_val > (UINT_MAX / 2))
			return (0);

		dec_val = dec_val << 1 | (*ptr - '0');
		ptr++;
	}

	return (dec_val);
}
