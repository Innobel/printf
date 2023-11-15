#include "main.h"
/**
 * output_unsigned - outputs unsigned num.
 * @arg: argument list
 * @buffer: Buffer array
 * @flag: Modifies flag.
 * @width: Width of the output
 * @precision: characters to be printed.
 * @size: Modifies size
 * Return: characters written to buffer.
 */
int output_unsigned(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int value = va_arg(arg, unsigned long int);

	value = convert_unsigned_num(value, size);

	if (value == 0)
		buffer[i--] = '\0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (value > 0)
	{
		buffer[i--] = (value % 10) + '0';
		value /= 10;
	}

	i++;

	return (_write_unsigned_number(0, i, buffer, flag, width, precision, size));
}

/**
 * output_octal - outputs numbers in base eight.
 * @arg: argument list
 * @buffer: Buffer array
 * @flag: Modifies flag.
 * @width: Width of the output
 * @precision: characters to be printed.
 * @size: Modifies size
 * Return: characters written to buffer.
 */
int output_octal(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int value = va_arg(arg, unsigned long int);
	unsigned long int num = value;

	UNUSED(width);

	value = convert_unsigned_num(value, size);

	if (value == 0)
		buffer[i--] = '\0';

	buffer[BUFFER_SIZE - 1] = '\0';

	for (; value > 0; value /= 8)
	{
		buffe[i--] = (value % 8) + '0';
	}

	if (flag & FLAG_HASH && num != 0)
		buffer[i--] = '0';

	i++;

	return (_write_unsigned_number(0, i, buffer, flag, width, precision, size));
}

/**
 * output_hexadecimal - outputs numbers in base eight.
 * @arg: argument list
 * @buffer: Buffer array
 * @flag: Modifies flag.
 * @width: Width of the output
 * @precision: characters to be printed.
 * @size: Modifies size
 * Return: characters written to buffer.
 */
int output_hexadecimal(va_list arg, char buffer[],
		int flag, int width, int precision, int size)
{
	return (output_hexa(arg, "0123456789abcdef", buffer, flag, /
				'x', width, precision, size));
}

/**
 * output_hexa - Convert an unsigned long integer to a hexa decimal string.
 * @arg: argument list
 * @map_to: An array representing the hexadeci character
 * @buffer: Buffer array
 * @flag: Modifies flag.
 * @flag_ch: flag character to be used.
 * @width: Width of the output
 * @precision: characters to be printed.
 * @size: Modifies size
 * Return: characters written to buffer.
 */
int output_hexa(va_list arg, char map_to[], char buffer[], int flag,
		char flag_ch, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int value = va_arg(arg, unsigned long int);
	unsigned long int num = value;

	UNUSED(width);

	value = convert_unsigned_num(value, size);

	if (value == 0)
		buffer[i--] = '0';

	for (; value > 0; value / 16)
	{
		buffer[i--] = map_to[value % 16];
	}

	if (flag & FLAG_HASH && num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (_write_unsigned_number(0, i, buffer, flag, width, precision, size));
}

/**
 * output_hexa_upper - output hexa decimal no in upper case.
 * @arg: argument list
 * @buffer: Buffer array
 * @flag: Modifies flag.
 * @width: Width of the output
 * @precision: characters to be printed.
 * @size: Modifies size
 * Return: characters written to buffer.
 */
int output_hexa_upper(va_list arg, char buffer[], 
		int flag, int width, int precision, int size)
{
	return (output_hexa(arg, "0123456789ABCDEF", buffer, flag, /
				'X', width, precision, size));
}
