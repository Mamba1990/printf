#include "main.h"
void printBuffer(char _buffer[], int *_buff_ind);
/**
 * _printf - function
 * @format: forma to print
 * Return: chars.
 */
int _printf(const char *format, ...)
{
        int j, _printed = 0, _printed_chars = 0;
        int _flags, _width, _precision, _size, _buff_ind = 0;
        va_list _list;
        char _buffer[BUFF_S];

        if (format == NULL)
                return (-1);
        va_start(_list, format);
        j = 0;
        while (format && format[j] != '\0')
        {
                if (format[j] != '%')
                {
                        _buffer[_buff_ind++] = format[j];
                        if (_buff_ind == BUFF_S)
                               printBuffer(_buffer, &_buff_ind);
                        _printed_chars++;
                }
                else
                {
                        printBuffer(_buffer, &_buff_ind);
                        _flags = getFlags(format, &j);
                        _width = getWidth(format, &j, _list);
                        _precision = getPrecision(format, &j, _list);
                        _size = getSize(format, &j);
                        ++j;
                        _printed = handlePrint(format, &j, _list, _buffer,
                                        _flags, _width, _precision, _size);
                        if (_printed == -1)
                                return (-1);
                        _printed_chars += _printed;
                }
                j++;
        }
        printBuffer(_buffer, &_buff_ind);
        va_end(_list);

        return (_printed_chars);
}
/**
 * printBuffer - Prints the content of the existent buffer
 * @_buffer: Array of chars
 * @_buff_index: the length.
 */

void printBuffer(char _buffer[], int *_buff_ind)
{
        if (*_buff_ind > 0)
        {
                write(1, &_buffer[0], *_buff_ind);
        *_buff_ind = 0;
        }
}
