#include "main.h"
/**
 * output_char - Handles the output of a character argument for _printf.
 * @arg: A va_list containing the character argument.
 * @buffer: The buffer to store the formatted output.
 * @flag: Flags specifying formatting options
 * @width: Minimum width of the output.
 * @precision: Number of characters to print for strings.
 * @size: Size specifier for the argumetn.
 * Return: The number of character written to the buffer.
 */
int output_char(va_list arg, char buffer[], int flag, int width, int precision,
		int size)
{
	char c = va_arg(arg, int); /* Get the character from va_list */

	return (_write_char(c, buffer, flag, width, precision, size));
}

/**
 * output_string - Outputs a string to the buffer.
 * @arg: The va_list containing the argument.
 * @buffer: The buffer to which the string is printed (unused).
 * @flag: Flags modifying the output (unused).
 * @width: Minimum width of the output (unused).
 * @precision: Number of characters to be printed (unused).
 * @size: Size modifier (unused).
 * Return: Number of character printed.
 */
int output_string(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
	char *str = va_arg(arg, char *);
	int len = 0, i;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = (precision >= 6) ? "      " : "(null)";

	len = _strlen(str);

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flag & FLAG_MINUS)
		{
			write(1, str, len);

			i = width - len;
			while (i-- > 0)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, str, len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * output_percent - Outputs a percent symbol to the buffer.
 * @arg: The va_list containing the argunment (unused).
 * @buffer: The buffer to which the percent symbol is printed (unused).
 * @flag: Flag modifying the output(unused).
 * @width: Mininum width of the output (unused).
 * @precision: Numver of characters to be printed (unused).
 * @size: Size modifier (unused).
 * Return: Always return write.
 */
int output_percent(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
	UNUSED(arg);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * output_int - Outputs an integer to the buffer.
 * @arg: The va_list containing the integer argument.
 * @buffer: The buffer to which the integer is printed (unused).
 * @flag: Flag modifyng the output.
 * @width: Mininum width of the ouptut.
 * @precision: Number of characters printed.
 * @size: Size modifier.
 * Return: Number printed
 */

int output_int(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
	int i = BUFFER_SIZE - 2; /* Start index from the second last position */
	int is_neg = 0;
	long int m = va_arg(arg, long int);
	unsigned long int number;

	m = convert_num(m, size);

	if (m == 0)
		buffer[i--] = '\0';

	buffer[BUFFER_SIZE - 1] = '\0';
	number = (unsigned long int)m;

	if (m < 0)
	{
		number = (unsigned long int)((-1) * m);
		is_neg = 1;
	}
	/* Extract digits one by one */
	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	/* call a helper function to handle width precision, and flag */
	return (_write_number(is_neg, i, buffer, flag, width, precision, size));
}

/**
 * output_binary - Outputs the binary representation of an unsigned integer.
 * @arg: The va_list containing the argument.
 * @buffer: The buffer to which the binary representation is printed.
 * @flag: Flags modifying the output (unused).
 * @width: Minimum width of the output (unused).
 * @precision: Number of characters to be printed (unused).
 * @size: Size modifier (unused).
 * Return: Number of characters printed.
 */
int output_binary(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
	unsigned int k, j, i, total;
	unsigned int b[32];
	int count;
	char z;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	k = va_arg(arg, unsigned int);
	j = 2147483648;
	b[0] = k / j;

	i = 1;
	while (i < 32)
	{
		j /= 2;
		b[i] = (k / j) % 2;
		i++;
	}

	i = 0;
	total = 0;
	count = 0;
	while (i < 32)
	{
		total += b[i];
		if (total || i == 31)
		{
			z = '0' + b[i];

			write(1, &z, 1);
			count++;
		}
		i++;
	}

	return (count);
}
