#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int length = _printf("String:[%s] character:[%c]\n", "I am a string ", 'H');

	printf("Number of characters printed: %d\n", length);
return (0);
}
