#include "main.h"

/**
 * _write_char - Write a character to the buffer with specified formatting.
 * @c: The character to be written.
 * @buffer: The buffer to store the formatted output.
 * @flag: Flags specifying formatting options.
 * @width: Minimum width of the output.
 * @precision: Number of characters to print for strings.
 * @size: Size specifier for the argument.
 *
 * Return: The number of characters written to the buffer
 */

int _write_char(char c, char buffer[], int flag, int width,
		int precision, int size)
{
	int i = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & FLAG_ZERO)
		padding = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		i = 0;

		while (i < width - 1)
		{
			buffer[BUFFER_SIZE - i - 2] = padding;
			i++;
		}

		if (flag & FLAG_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * _write_number - Writes a number to the standard output.
 * @is_neg: Flag indicating whether the number is negative.
 * @index: The starting index of the number in the buffer.
 * @buffer: The buffer containing the number to be written.
 * @flag: Flags modifying the output.
 * @width: Minimum width of the output.
 * @precision: Number of characters to be printed.
 * @size: Size modifier.
 * Return: The number of characters written.
 */
int _write_number(int is_neg, int index, char buffer[], int flag, int width,
		int precision, int size)
{
	int len = BUFFER_SIZE - index - 1;
	char padding = ' ';
	int written_chars = 0;

	UNUSED(size);

	if ((flag & FLAG_ZERO) && !(flag & FLAG_MINUS))
		padding = '0';

	/* Handles special characters for negative, plus, or space */
	if (is_neg)
		written_chars = '-';
	else if (flag & FLAG_PLUS)
		written_chars = '+';
	else if (flag & FLAG_SPACE)
		written_chars = ' ';

	/* Call the _write_num function to handle the actural writing */
	return (_write_num(index, buffer, flag, width, precision, len, padding,
				written_chars));
}


/**
 * _write_num - Writes a number to the standard output.
 * @index: The starting index of the number in the buffer.
 * @buffer: The buffer containing the number to be written.
 * @flag: Flags modifying the output.
 * @width: Minimum width of the output.
 * @precision: Number of characters to be printed.
 * @len: Length of the number.
 * @padding: Padding character.
 * @extra_ch: Extra character to be printed before the number.
 * Return: The number of characters written.
 */
int _write_num(int index, char buffer[], int flag, int width, int precision,
		int len, char padding, char extra_ch)
{
	int i, padding_start = 1;
	/* Handle special case: ".0d" where no character is required. */
	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0' &&
			width == 0)
		return (0);
	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padding = ' ';
	if (precision > 0 && precision < len)
		padding = ' ';
	while (precision > len)
		buffer[--index] = '0', len++;
	if (extra_ch != 0)
		len++;

	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = padding;
		buffer[i] = '\0';
		if (flag & FLAG_MINUS && padding == ' ')
		{
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & FLAG_MINUS) && padding == ' ')
		{
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], len)); }
		else if (!(flag & FLAG_MINUS) && padding == '0')
		{
			if (extra_ch)
				buffer[--padding_start] = extra_ch;
			return (write(1, &buffer[padding_start], i - padding_start) +
					write(1, &buffer[index], len - (1 - padding_start)));
		}
	}
	if (extra_ch)
		buffer[--index] = extra_ch;
	return (write(1, &buffer[index], len)); }

/**
 * _writ_unsigned_number - Prints the unsigned num to the buffer.
 * @is_neg: integer parameter (signed).
 * @index: Starting index in the buffer.
 * @buffer: buffer which the number is written.
 * @flag: modifies output (unused).
 * @width: width of the output.
 * @precision: characters to be printed.
 * @size: Modifies size (not used).
 * Return: character written to the buffer.
 */
int _write_unsigned_number(int is_neg, int index, char buffer[], int flag,
		int width, int precision, int size)
{
	int len = BUFFER_SIZE - index - 1, i = 0;
	char padding = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < len)
		padding = ' ';
	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}

	if ((flag & FLAG_ZERO) && !(flag & FLAG_MINUS))
		padding = '0';

	if (width > len)
	{
		while (i < width - len)
			buffer[i++] = padding;

		buffer[i] = '\0';

		if (flag & FLAG_MINUS)
			return (write(1, &buffer[index], len) + write(1, &buffer[0], i));
		else
			return (write(1, &buffer[0], i) + write(1, &buffer[index], len));
	}

	return (write(1, &buffer[index], len));
}
/**
 * _write_pointer - Writes a pointer address to the buffer.
 * @buffer: The buffer to which the pointer address is written.
 * @index: starting index in the buffer inter.
 * @len: length of the pointer.
 * @width: width of  output
 * @flag: Modifies the output.
 * @padding: padding character.
 * @extra_ch: Extra character to be included in the output.
 * @padding_start: Starting index for padding.
 * Return: characters written to the buffer.
 */
int _write_pointer(char buffer[], int index, int len, int width, int flag,
		char padding, char extra_ch, int padding_start)
{
	int i = 3;

	if (width > len)
	{
		while (i < width - len + 3)
			buffer[i++] = padding;
		buffer[i] = '\0';
		if (flag & FLAG_MINUS && padding == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & FLAG_MINUS) && padding == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], len));
		}
		else if (!(flag & FLAG_MINUS) && padding == '0')
		{
			if (extra_ch)
				buffer[--padding_start] = extra_ch;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padding_start], i - padding_start) +
					write(1, &buffer[index], len - (1 - padding_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_ch)
		buffer[--index] = extra_ch;
	return (write(1, &buffer[index], BUFFER_SIZE - index - 1));
}
