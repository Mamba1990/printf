#include "main.h"

/**
 * getSize - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @j: List of arguments to be printed.
 *
 * Return: Precision.
 */
int getSize(const char *format, int *j)
{
        int curr_j = *j + 1;
        int _size = 0;

        if (format[curr_j] == 'l')
                _size = SIZE_LONG;
        else if (format[curr_j] == 'h')
                _size = SIZE_SHORT;

        if (_size == 0)
                *j = curr_j - 1;
        else
                *j = curr_j;

        return (_size);
}
