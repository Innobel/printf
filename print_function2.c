#include "main.h"
/**
* output_pointer - Convert a pointer address to a hexadecimal string.
* @arg: variable arguments
* @buffer: A character array.
* @flag: Flags indexing special formatting options
* @width:  Width field.
* @precision: Precision field.
* @size: Size of field for formatting.
* Return: No of characters written to the buffer.
*/
int output_pointer(va_list arg, char buffer[], int flag, int width,
int precision, int size)
{
char extra_ch = 0, padding = ' ';
int index = BUFFER_SIZE - 2, len = 2, padding_start = 1;
unsigned long num_address;
char map_to[] = "0123456789abcdef";
void *address = va_arg(arg, void *);

UNUSED(width);
UNUSED(size);

if (address == NULL)
return (write(1, "(nil)", 5));

buffer[BUFFER_SIZE - 1] = '\0';
UNUSED(precision);

num_address = (unsigned long)address;

for (; num_address > 0; num_address /= 16)
{
buffer[index--] = map_to[num_address % 16];
len++;
}

if ((flag & FLAG_ZERO) && !(flag & FLAG_MINUS))
padding = '0';
if (flag & FLAG_PLUS)
extra_ch = '+', len++;
else if (flag & FLAG_SPACE)
extra_ch = ' ', len++;

index++;

return (write_pointer(buffer, index, len, width, flag, padding, extra_ch, /
			padding_start));
}

/**
* output_not_printable - Print a string with non-printable characters
* @arg: variable arguments
* @buffer: A character array
* @flag: Flags indexing special formatting options
* @width:  Width field
* @precision: Precision field
* @size: Size of field for formatting
* Return: No of characters written to the buffer.
*/
int output_not_printable(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
int i;
int hex_offset = 0;
char *str = va_arg(arg, char *);

UNUSED(flag);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
return (write(1, "(null)", 6));

for (i = 0; str[i] != '\0'; i++)
{
if (check_printable(str[i]))
buffer[i + hex_offset] = str[i];
else
hex_offset += encode_hexa_char(str[i], buffer, i + hex_offset);
}

buffer[i + hex_offset] = '\0';

return (write(1, buffer, i + hex_offset));
}

/**
* output_rot13string - Encode a string using the ROT13 algorithm.
* @arg: variable arguments
* @buffer: A character array (not used in this implementation)
* @flag: indicating special formatting options(not used in this implementation)
* @width:  width field for formatting (not used in this implementation)
* @precision:  precision field for formatting (not used in this implementation)
* @size: Modifies size.
* Return: no of character written to the standard output.
*/
int output_rot13string(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
char x;
char *input_str;
unsigned int i, j;
int count = 0;
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

input_str = va_arg(arg, char *);
UNUSED(buffer);
UNUSED(flag);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (input_str == NULL)
input_str = "(NLU)";

i = 0;
while (input_str[i] != '\0')
{
j = 0;
while (alphabet[j] != '\0')
{
if (alphabet[j] == input_str[i])
{
x = rot13[j];
write(1, &x, 1);
count++;
break;
}
j++; }
if (alphabet[j] == '\0')
{
x = input_str[i];
write(1, &x, 1);
count++;
}
i++;
}

return (count); }

/**
* output_reverse - Print a string in Reverse.
* @arg: variable arguments
* @buffer: A character array
* @flag: Flags indexing special formatting options
* @width:  Width field
* @precision: Precision field
* @size: Size of field for formatting
* Return: No of characters written to the buffer.
*/
int output_reverse(va_list arg, char buffer[], int flag, int width,
		int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	str = va_list(arg, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}

	i = 0;
	while (str[i])
	{
		i++;
	}

	i = i - 1;
	while (i >= 0)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
		i--;
	}

	return (count);
}
