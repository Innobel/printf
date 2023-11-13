In this project we are expected to handle the following problems
1. write a function that produces output according to a format: c, s, %
2. Handle the following conversion specifiers: d, i
3. Handle the following custom conversion specifiers: b(unsigned int
argument is converted to binary
4. Handle the following conversion specifiers: u, o, x, X
5. a localbuffer of 1024 chars in order to call write as little as possible
6. Handle the following custom conversion specifier: S(prints string) Non 
printable character (0 < ASCII value < 32 or >= 127) are printed this way:\x,
followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
7. Handle the following conversion specifier: p.
8. Handle the following flag characters for non-custom conversion specifiers:
+, space, #
9. Handle the following length modifiers for non-custom conversion specifiers:
l,h,conversion specifiers to handle: d, i, u, o, x, X
10. Handle the field width for non-custom conversion specifiers.
11. Handle the precision for non-custom conversion specifiers.
12. Handle the 0 flag character for non-custom conversion specifiers.
13. Handle the - flag character for non-custom conversion specifiers.
14. Handle the following custom conversion specifier: r: prints the reverse string
15. Handle the following custom conversion specifier: R: prints the rot13'ed string
16. All the above options work well together.
