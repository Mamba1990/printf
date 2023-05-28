#include <stdio.h>
#include <stdarg.h>


int _printf(const char *format, ...)
{
    va_list argms;
    int length = 0;  /* Track the number of characters printed*/

    va_start(argms, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;  /* Move past the '%' */

            /* Handle the conversion specifiers */
            switch (*format)
            {
                case 'c':
                {
                    int _char = va_arg(argms, int);
                    putchar(_char);
                    length++;
		    break;
                }
                case 's':
                {
                    const char *ss = va_arg(argms, const char *);
                    while (*ss != '\0')
                    {
                        putchar(*ss);
                        ss++;
                        length++;
                    }
                    break;
                }
                case '%':
                {
                    putchar('%');
                    length++;
                    break;
                }
                default:
                    break;
            }
        }
        else
        {
            putchar(*format);
            length++;
                                                                                           
        }

        format++;
    }

    va_end(argms);

    return (0);
}
