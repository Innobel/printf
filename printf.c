#include "main.h"
/**
 * my_buffer - Prints the content of the given buffer and reset the counter
 * @buffer: The buffer containing the character to be printed
 * @buff_index: A pointer to the index tracking the buffer
 */

void my_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
	{
		write(1, &buffer[0], *buff_index);

		*buff_index = 0;
	}
}

/**
* _printf - Custom implementation of the printf function.
* @format: The format string specifying.
* @...: Variable number of arguments based on the format specifier
* Return: The total number of characters written, excluding the null terminator
*         or -1 if an error occurs.
*/
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flag, width, precision, size, buffer_index = 0;
va_list ap;
char buffer[BUFFER_SIZE];

if (format == NULL)
return (-1);

va_start(ap, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buffer_index++] = format[i];
if (buffer_index == BUFFER_SIZE)
my_buffer(buffer, &buffer_index);
printed_chars++;
}
else
{
my_buffer(buffer, &buffer_index);
flag = _flag(format, &i);
width = _width(format, &i, ap);
precision = _precision(format, &i, ap);
size = _size(format, &i);
++i;
printed = process_format_specifier(format, &i, ap, buffer,
flag, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

my_buffer(buffer, &buffer_index);

va_end(ap);

return (printed_chars);
}

