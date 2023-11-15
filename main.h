#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
* struct fmt - Struct op
*
* @fmt: format.
* @fn: function associated.
*/
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
* typedef struct fmt fmt_t - Struct op
*
* @fmt:  format.
* @fm_t:  function associated.
*/
typedef struct fmt fmt_t;


/* _printf prototype */
void my_buffer(char buffer[], int *buff_count);
int _printf(const char *format, ...);

/* print_function prototype */
int output_char(va_list arg, char buffer[], int flag, int width, int precision,
int size);
int output_string(va_list arg, char buffer[], int flag, int width,
int precision, int size);
int output_percent(va_list arg, char buffer[], int flag, int width,
int precision, int size);
int output_int(va_list arg, char buffer[], int flag, int width,
int precision, int size);
int output_binary(va_list arg, char buffer[], int flag, int width,
int precision, int size);

/* print_function1 prototype */
int output_unsigned(va_list arg, char buffer[], int flag, int width,
int precision, int size);
int output_octal(va_list arg, char buffer[], int flag, int width,
int precision, int size);
int output_hexa(va_list arg, char map_to[], char buffer[], int flag,
char flag_ch, int width, int precision, int size);
int output_hexadecimal(va_list arg, char buffer[],
int flag, int width, int precision, int size);
int output_hexa_upper(va_list arg, char buffer[],
int flag, int width, int precision, int size);

/* print_function2 prototype */
int output_pointer(va_list arg, char buffer[], int flag, int width,
int precision, int size);
int output_not_printable(va_list arg, char buffer[], int flag, int width,
int precision, int size);
int output_rot13string(va_list arg, char buffer[], int flag, int width,
int precision, int size);
int output_reverse(va_list arg, char buffer[], int flag, int width,
int precision, int size);

/* get_function prototype */
int _flag(const char *format, int *i);
int _precision(const char *format, int *i, va_list ap);
int _width(const char *format, int *i, va_list ap);
int _size(const char *format, int *i);


/* helper_function prototype */

int _size(const char *format, int *i);
int check_printable(char c);
int encode_hexa_char(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_num(long int n, int size);
unsigned long int convert_unsigned_num(unsigned long int n, int size);
int _strlen(const char *str);

/* process_format_specifier prototype */

int process_format_specifier(const char *fmt, int *index, va_list arg,
char buffer[], int flag, int width, int precision, int size);

/* _write_function prototype */

int _write_char(char c, char buffer[], int flag, int width,
int precision, int size);
int _write_number(int is_neg, int index, char buffer[], int flag, int width,
int precision, int size);
int _write_num(int index, char buffer[], int flag, int width, int precision,
int len, char padding, char extra_ch);
int _write_unsigned_number(int is_neg, int index, char buffer[], int flag,
int width, int precision, int size);
int _write_pointer(char buffer[], int index, int len, int width, int flag,
char padding, char extra_ch, int padding_start);

#endif /* MAIN_H */
