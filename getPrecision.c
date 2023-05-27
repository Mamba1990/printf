#include "main.h"
/**
 * getPrecision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @j: List of arguments to be printed.
 * @_list: list of arguments.
 *
 * Return: Precision.
 */
 int getPrecision(const char *format, int *j, va_list _list)
{
	int curr_j = *j + 1;
	int _precision = -1;

	if (format[curr_j] != '.')
		return (_precision);

	_precision = 0;
	for (curr_j += 1; format[curr_j] != '\0'; curr_j++)
	{
		if (is_digit(format[curr_j]))
		{
			_precision *= 10;
			_precision += format[curr_j] - '0';
		}
		else if (format[curr_j] == '*')
		{
			curr_j++;
			_precision = va_arg(_list, int);
			break;
		}
		else
			break;
	}

	*j = curr_j - 1;

	return (_precision);
}
