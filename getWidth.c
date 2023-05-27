#include "main.h"
/** get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int getWidth(const char *format, int *j, va_list _list)
{
        int curr_j;
        int _width = 0;

        for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
        {
                if (is_digit(format[curr_j]))
 		{	
                        _width *= 10;
                        _width += format[curr_j] - '0';
                }
                else if (format[curr_j] == '*')
                {
                        curr_j++;
                        _width = va_arg(_list, int);
                        break;
                }
                else
                        break;
        }

        *j = curr_j - 1;

        return (_width);
}
                                                                        
