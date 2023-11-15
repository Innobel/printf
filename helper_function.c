#include "main.h"
/**
 * check_printable - Checks if a character is printable.
 * @c: The character to be checked.
 * * Return: 1 if printable, if not return  0.
 */
int check_printable(char c)
{
	return (c >= 32 && c < 127);
}


/**
 * encode_hexa_char - Encodes a character as a hexadecimal code.
 * @ascii_code: The character to be encoded.
 * @buffer: The buffer to which the encoded code is added
 * @i: The index in the buffer to start adding
 * Return: updated index after adding the hexadecimal code.
 */
int encode_hexa_char(char ascii_code, char buffer[], int i)
{
	unsigned char high_nibble, low_nibble;
	const char hex_digits[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	/* Ensure that the index is within bounds */
	if (i >= 0 && i < BUFFER_SIZE - 2)
	{
		high_nibble = (ascii_code >> 4) & 0xF;
		low_nibble = ascii_code & 0xF;

		/* Append the hexa_decimal */
		buffer[i++] = '\\';
		buffer[i++] = 'x';
		buffer[i++] = hex_digits[high_nibble];
		buffer[i++] = hex_digits[low_nibble];
	}

	return (i);
}

/**
 * is_digit - Checks if character is digit
 * @c: character to be checked
 * Return: 1 when successful other wise 0.
 */
int is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);

	return (0);
}


/**
 * convert_num - Converts the integer based
 * @n: integer to be converted.
 * @size: size modifier.
 * Return: The converted integer.
 */

long int convert_num(long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((short)n);

	return ((int)n);
}

/**
 * convert_unsigned_num - Converts the integer based on the size modifier.
 * @n: integer to be converted.
 * @size: size modifier (S_LONG or S_SHORT).
 * Return: The converted integer.
 */
unsigned long int convert_unsigned_num(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (n); /* No conversion needed for long */
	else if (size == S_SHORT)
		return ((unsigned short)n); /* convert to unsigned short */

	return (n); /* Default case: no conversion */
}
