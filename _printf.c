#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - function
 * @format: forma to print
 * Return: chars.
 */
int _printf(const char *format, ...)
{
	va_list argms;
	int length = 0;

	va_start(argms, format);
	while (*format)

	{
		if (*format == '%')
		{
			format++;
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

					length += printf("%s", ss);
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
return (length);
}
