/* printf.c */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    for (ptr = format; ptr && *ptr; ++ptr)
    {
        if (*ptr == '%' && ptr[1] != '\0')
        {
            /* Handle conversion specifier */
            ++ptr; /* Move to the character after '%' */
            switch (*ptr)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += write(1, va_arg(args, char *), _strlen(va_arg(args, char *)));
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, &(*ptr), 1);
                    break;
            }
        }
        else
        {
            /* Regular character, just print it */
            count += write(1, &(*ptr), 1);
        }
    }

    va_end(args);

    return count;
}

int _strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}
