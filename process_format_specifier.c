#include "main.h"

/**
* process_format_specifier - Handle and process a format specifier.
* @fmt: Format string.
* @index: Pointer to the index string.
* @arg: List of variable arguments.
* @buffer: Character array.
* @flag: Flags for special formatting options.
* @width: Width field.
* @precision: Precision field.
* @size: Size of field.
* Return: No of characters written to the buffer.
*/
int process_format_specifier(const char *fmt, int *index, va_list arg, /
		char buffer[], int flag, int width, int precision, int size)
{
int unknown_length = 0, printed_chars = -1;
fmt_t format_list[] = {
{'c', output_char}, {'s', output_string}, {'%', output_percent},
{'i', output_int}, {'d', output_int}, {'b', output_binary},
{'u', output_unsigned}, {'o', output_octal}, {'x', output_hexadecimal},
{'X', output_hexa_upper}, {'p', output_pointer}, {'S', output_not_printable},
{'r', output_reverse}, {'R', output_rot13string}, {'\0', NULL}
};

int i = 0;
while (format_list[i].fmt != '\0')
{
if (fmt[*index] == format_list[i].fmt)
return (format_list[i].fn(arg, buffer, flag, width, precision, size));
i++; }

if (format_list[i].fmt == '\0')
{
if (fmt[*index] == '\0')
return (-1);
unknown_length += write(1, "%%", 1);
if (fmt[*index - 1] == ' ')
unknown_length += write(1, " ", 1);
else if (format_width)
{
--(*index);
while (fmt[*index] != ' ' && fmt[*index] != '%')
--(*index);
if (fmt[*index] == ' ')
--(*index);
return (1); }

unknown_length += write(1, &fmt[*index], 1);
return (unknown_length);
}

return (printed_chars);
}
