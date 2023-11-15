#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++; /* Move to the next character after % */

            if (*format == 'd' || *format == 'i') {
                int num = va_arg(args, int);
                printf("%d", num);
                count += snprintf(NULL, 0, "%d", num);
            } else {
                putchar('%');
                putchar(*format);
                count += 2; /* Increment count for '%' and the character after '%' */
            }
        } else {
            putchar(*format);
            count++;
        }

        format++; /* Move to the next character in the format string */
    }

    va_end(args);
    return count;
}
