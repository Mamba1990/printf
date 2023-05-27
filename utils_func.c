#include "main.h"

/**
 * isPrintable - Evaluates if a char is printable
 * @cc: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 * /
int isPrintable(char cc)
{
	if (cc >= 32 && cc < 127)
		return (1);

	return (0);
}

/**
 * appendHexaCode - Append ascci in hexadecimal code to buffer
 * @_buffer: Array of chars.
 * @j: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 * /
int appendHexaCode(char ascii_code, char _buffer[], int j)
{
	char _map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;
	
	_buffer[j++] = '\\';
	_buffer[j++] = 'x';

	_buffer[j++] = map_to[ascii_code / 16];
	_buffer[j] = _map_to[ascii_code % 16];

	return (3);
}

/**
 * * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 * /
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

#include "main.h"
/**
 * convertSizeNumber - Casts a number to the specified size
 * @number: Number to be casted.
 * @_size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 * /
long int convertSizeNumber(long int number, int _size)
{
	if (_size == SIZE_LONG)
		return (number);
	else if (size == SIZE_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * convertSizeUnsgnd - Casts a number to the specified size
 * @number: Number to be casted
 * @_size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 * /
long int convertSizeUnsgnd(unsigned long int number, int _size)
{
	if (_size == SIZE_LONG)
		return (num);
	else if (_size == SIZE_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}


