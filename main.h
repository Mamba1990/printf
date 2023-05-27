#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
/**
 * struct _fmt - Stuct format
 *
 * @_fmt: The format.
 * @fn: The associated function
 */
struct _fmt
{
        char _fmt;
        int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct _fmt fmt_t - Struct op
 *
 * @_fmt: The format.
 * @fm_t: The associated function.
 */

typedef struct _fmt fmt_t;

/* handelPrint prototype */
int handlePrint(const char *_fmt, int *j,
va_list _list, char _buffer[],
int _flags, int _width, int _precision, int _size);

/** Funtions to print chars and strings and percent */
int printChar(va_list _types, char _buffer[],
                int _flags, int _width, int _precision, int _size);
int printString(va_list _types, char _buffer[],
                int _flags, int _width, int _precision, int _size);
int printPercent(va_list _types, char _buffer[],
                int _flags, int _width, int _precision, int _size);

/* our _printf prototype */
int _printf(const char *format, ...);
/* Funciotns to handle other specifiers - getters */
int getFlags(const char *format, int *j);
int getWidth(const char *format, int *j, va_list _list);
int getPrecision(const char *format, int *j, va_list _list);
int getSize(const char *format, int *j);


/** UTILS */
int isPrintable(char);
int appendHexaCode(char, char[], int);
int is_digit(char);

/**Handlers*/
int handleWriteChar(char cc, char _buffer[],
                int _flags, int _width, int _precision, int _size);

/* FLAGS */
#define FG_MINUS 1
#define FG_PLUS 2
#define FG_ZERO 4
#define FG_HASH 8
#define FG_SPACE 16

#define BUFF_S 1024
#define SIZE_LONG 2
#define SIZE_SHORT 1

#endif /* MAIN_H */
