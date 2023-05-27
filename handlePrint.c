#include "main.h"
/**
 * handlePrint - Prints an argument based on its type
 * @_fmt: Formatted string in which to print the arguments.
 * @_list: List of arguments to be printed.
 * @_ind: ind.
 * @_buffer: Buffer array to handle print.
 * @_flags: Calculates active flags
 * @_width: get width.
 * @_precision: Precision specification
 * @_size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *_fmt, int *_ind, va_list _list, char _buffer[],
	int _flags, int _width, int _precision, int _size)
{
	int j, unknown_l = 0, _printed_chars = -1;
	fmt_t _fmt_types[] = {
		{'c', printChar}, {'s', printString}, {'%', printPercent},
		{'i', printInt}, {'d', printInt}, {'b', printBinary},
		{'u', printUnsigned}, {'o', printOctal}, {'x', printHexadecimal},
		{'X', printHexaUpper}, {'p', printPointer}, {'S', printNonPrintable},
		{'r', printReverse}, {'R', printRot13string}, {'\0', NULL}
	};
	for (j = 0; _fmt_types[j]._fmt != '\0'; j++)
		if (_fmt[*_ind] == _fmt_types[j]._fmt)
			return (_fmt_types[j].fn(_list,_buffer, _flags, _width, _precision, _size));

	if (_fmt_types[i]._fmt == '\0')
	{
		if (_fmt[*ind] == '\0')
			return (-1);
unknown_l += write(1, "%%", 1);
		if (_fmt[*_ind - 1] == ' ')
			unknown_l += write(1, " ", 1);
		else if (_width)
		{
			--(*_ind);
			while (_fmt[*_ind] != ' ' && _fmt[*_ind] != '%')
				--(*_ind);
			if (_fmt[*_ind] == ' ')
				--(*_ind);
			return (1);
		}
		unknown_l += write(1, &_fmt[*_ind], 1);
		return (unknown_l);
	}
	return (_printed_chars);
}

