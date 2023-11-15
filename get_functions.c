#include "main.h"
/**
 * _flag - Retrives active flags based on the provided string.
 * @format: The format string containing potential flags.
 * @i: A pointer to the current index within the format string.
 * Return: The integer representation of active flags.
 */
int _flag(const char *format, int *i)
{
int j, current_i;
int flag = 0;
const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAG_ARR[] = {
FLAG_MINUS,
FLAG_PLUS,
FLAG_ZERO,
FLAG_HASH,
FLAG_SPACE,
0};
int num_flag = sizeof(FLAG_CH) / sizeof(FLAG_CH[0]);

current_i = *i + 1;  /* Initialization */

while (format[current_i] != '\0')
{
for (j = 0; j < num_flag; j++)
{
if (format[current_i] == FLAG_CH[j])
{
flag |= FLAG_ARR[j];
break;
}
}

if (j == num_flag)
break;

current_i++;
}

*i = current_i - 1;

return (flag);
}

/**
 * _precision - Retrieves the precision value from the format string.
 * @format: The format string containing potential precision information.
 * @i: The va_list representing the variable arguments.
 * @ap: The va_list representing the variabe arguments.
 * Return: The precision value, or -1 if no precision is specified.
 */
int _precision(const char *format, int *i, va_list ap)
{
	int current_i = *i + 1;
	int precision = -1;

	if (format[current_i] != '.')
		return (precision);

	precision = 0;

	for (current_i += 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			precision *= 10;
			precision += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			precision = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	*i = current_i - 1;

	return (precision);
}

/**
 * _size - Retrieves the size value from the format string.
 * @format: The format string containing potential size information.
 * @i: A pointer to the current index within the format string.
 *
 * Return: The size value, or 0 if no size is specified.
 */

int _size(const char *format, int *i)
{
	int current_i = *i + 1;
	int size = 0;

	while (format[current_i] != '\0')
	{
		if (format[current_i] == 'l')
		{
			size |= S_LONG;
		}
		else if (format[current_i] == 'h')
		{
			size |= S_SHORT;
		}
		else
		{
			break;
		}

		current_i++;
	}

	*i = current_i - 1;

	return (size);
}

/**
 * _width - Retrieves the width value from the format string.
 * @format: the format string containing potential width information.
 * @i: A pointer to the current index within the format string.
 * @ap: The va_list to retrieve arguments for dynamic width.
 * Return: The width value, or -1 if no width is specified.
 */

int _width(const char *format, int *i, va_list ap)
{
	int current_i = *i + 1;
	int width = -1;

	if (format[current_i] == '*')
	{
		width = va_arg(ap, int);
		current_i++;
	}
	else
	{
		width = 0;
		while (is_digit(format[current_i]))
		{
			width *= 10;
			width += format[current_i] - '0';
			current_i++;
		}
	}

	*i = current_i - 1;

	return (width);
}
