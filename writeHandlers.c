#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handleWriteChar - Prints a string
 * @cc: char types.
 * @_buffer: Buffer array to handle print
 * @_flags:  Calculates active flags.
 * @_width: get width.
 * @_precision: precision specifier
 * @_size: Size specifier
 *
 * Return: Number of chars printed.
 * /
int handleWriteChar(char cc, char _buffer[],
	int _flags, int _width, int _precision, int _size)
{ /* char is stored at left and paddind at buffer's right */
	int j = 0;
	char _padd = ' ';

	UNUSED(_precision);
	UNUSED(_size);

	if (_flags & FG_ZERO)
		_padd = '0';
	_buffer[j++] = cc;
	_buffer[j] = '\0';

	if (_width > 1)
	{
		_buffer[BUFF_S - 1] = '\0';
		for (j = 0; j < _width - 1; j++)
			_buffer[BUFF_S - j - 2] = _padd;

		if (_flags & FG_MINUS)
			return (write(1, &_buffer[0], 1) +
					write(1, &_buffer[BUFF_S - j - 1], _width - 1));
		else
			return (write(1, &buffer[BUFF_S - j - 1], _width - 1) +
					write(1, &_buffer[0], 1));
	}

	return (write(1, &_buffer[0], 1));
}
/************************* WRITE NUMBER *************************/
/**
 * writeNumber - Prints a string
 * @isNegative: Lista of arguments
 * @_ind: char types.
 * @_buffer: Buffer array to handle print
 * @_flags:  Calculates active flags
 * @_width: get width.
 * @_precision: precision specifier
 * @_size: Size specifier
 *
 * Return: Number of chars printed.
 * /
nt writeNumber(int isNegative, int _ind, char _buffer[],
	int _flags, int _width, int _precision, int _size)
{
	int _length = BUFF_S - _ind - 1;
	char _padd = ' ', _extra_ch = 0;

	UNUSED(_size);

	if ((_flags & FG_ZERO) && !(_flags & FG_MINUS))
		padd = '0';
	if (isNegative)
		_extra_ch = '-';
	else if (_flags & FG_PLUS)
		_extra_ch = '+';
	else if (_flags & FG_SPACE)
		_extra_ch = ' ';

	return (write_num(_ind, _buffer, _flags, _width, _precision,
		_length, _padd, _extra_ch));
}

/**
 * writeNum - Write a number using a bufffer
 * @_ind: Index at which the number starts on the buffer
 * @_buffer: Buffer
 * @_flags: Flags
 * @_width: width
 * @_prec: Precision specifier
 * @_length: Number length
 * @_padd: Pading char
 * @_extra_c: Extra char
 *
 * Return: Number of printed chars.
 * /
int writeNum(int _ind, char _buffer[],
	int flags, int width, int prec,
	int _length, char _padd, char _extra_c
{
	int j, _padd_start = 1;

	if (_prec == 0 && _ind == BUFF_S - 2 && _buffer[_ind] == '0' && _width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (_prec == 0 && _ind == BUFF_S - 2 && _buffer[_ind] == '0')
		_buffer[_ind] = _padd = ' '; /* width is displayed with padding ' ' */
	if (_prec > 0 && _prec < _length)
		_padd = ' ';
	while (_prec > _length)
		_buffer[--_ind] = '0', _length++;
	if (_extra_c != 0)
		_length++;
	if (_width > _length)
	{
		for (j = 1; j < _width - _length + 1; j++)
			_buffer[j] = _padd;
		buffer[j] = '\0';
		if (_flags & FG_MINUS && _padd == ' ')/* Asign extra char to left of buffer */
		{
			if (_extra_c)
				_buffer[--_ind] = _extra_c;
			return (write(1, &_buffer[_ind], _length) + write(1, &_buffer[1], j - 1));
		}
		else if (!(_flags & FG_MINUS) && _padd == ' ')/* extra char to left of buff */
		{
			if (_extra_c)
				buffer[--_ind] = _extra_c;
			return (write(1, &_buffer[1], j - 1) + write(1, &_buffer[_ind], _length));
		}
		else if (!(_flags & FG_MINUS) && _padd == '0')/* extra char to left of padd */
		{
			if (_extra_c)
				_buffer[--_padd_start] = _extra_c;
			return (write(1, &_buffer[_padd_start], i - _padd_start) +
					write(1, &_buffer[_ind], _length - (1 - _padd_start)));
		}
	}
	if (_extra_c)
		_buffer[--_ind] = _extra_c;
	return (write(1, &_buffer[_ind], _length));
}

/**
 * writeUnsgnd - Writes an unsigned number
 * @_is_negativ: Number indicating if the num is negative
 * @_ind: Index at which the number starts in the buffer
 * @_buffer: Array of chars
 * @_flags: Flags specifiers
 * @_width: Width specifier
 * @_precision: Precision specifier
 * @_size: Size specifier
 *
 * Return: Number of written chars.
 * /
int writeUnsgnd(int _is_negative, int _ind,
	char _buffer[],
	int _flags, int _width, int _precision, int _size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int _length = BUFF_S - _ind - 1, j = 0;
	char _padd = ' ';
	
	UNUSED(_is_negative);
	UNUSED(_size);

	if (_precision == 0 && _ind == BUFF_S - 2 && _buffer[_ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (_precision > 0 && _precision < _length)
		_padd = ' ';

	while (_precision > _length)
	{
		_buffer[--_ind] = '0';
		_length++;
	}

	if ((_flags & FG_ZERO) && !(_flags & FG_MINUS))
		_padd = '0';
	
	if (_width > _length)
	{
		for (j = 0; j < _width - _length; j++)
			_buffer[j] = _padd;

		buffer[j] = '\0';

		if (_flags & FG_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &_buffer[_ind], _length) + write(1, &_buffer[0], j));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &_buffer[0], j) + write(1, &_buffer[_ind], _length));
		}
	}

	return (write(1, &_buffer[_ind], _length));
}

/**
 * writePointer - Write a memory address
 * @_buffer: Arrays of chars
 * @_ind: Index at which the number starts in the buffer
 * @_length: Length of number
 * @_width: Wwidth specifier
 * @_flags: Flags specifier
 * @_padd: Char representing the padding
 * @_extra_c: Char representing extra char
 * @__padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 * /
int writePointer(char _buffer[], int _ind, int _length,
	int _width, int _flags, char _padd, char _extra_c, int _padd_start)
{
	int j;

	if (_width > _length)
	{
		for (j = 3; j < _width - _length + 3; j++)
			_buffer[j] = _padd;
		_buffer[j] = '\0';
		if (_flags & FG_MINUS && _padd == ' ')/* Asign extra char to left of buffer */
		{
			_buffer[--_ind] = 'x';
			_buffer[--_ind] = '0';
			if (_extra_c)
				_buffer[--_ind] = _extra_c;
			return (write(1, &_buffer[_ind], _length) + write(1, &_buffer[3], j - 3));
		}
		else if (!(_flags & FG_MINUS) && _padd == ' ')/* extra char to left of buffer */
		{
			_buffer[--_ind] = 'x';
			_buffer[--_ind] = '0';
			if (_extra_c)
				buffer[--_ind] = _extra_c;
			return (write(1, &_buffer[3], j - 3) + write(1, &_buffer[_ind], _length));
		}
		else if (!(_flags & FG_MINUS) && _padd == '0')/* extra char to left of padd */
		{
			if (_extra_c)
				_buffer[--_padd_start] = _extra_c;
			_buffer[1] = '0';
			_buffer[2] = 'x';
			return (write(1, &_buffer[_padd_start], j - _padd_start) +
					write(1, &_buffer[_ind], _length - (1 - _padd_start) - 2));
			}
		}
		_buffer[--_ind] = 'x';
		_buffer[--_ind] = '0';
		if (_extra_c)
			_buffer[--_ind] = _extra_c;
		return (write(1, &_buffer[_ind], _BUFF_S - _ind - 1));
}


 
