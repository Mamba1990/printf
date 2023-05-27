#include "main.h"
/**
 * printChar - Prints a char
 * @_types: List a of arguments
 * @_buffer: Buffer array to handle print
 * @_flags:  Calculates active flags
 * @_width: Width
 * @_precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */

int printChar(va_list _types, char _buffer[],
        int _flags, int _width, int _precision, int _size)
{
        char cc = va_arg(_types, int);

        return (handleWriteChar(cc, _buffer, _flags, _width, _precision, _size));
}
