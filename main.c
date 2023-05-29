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
	int len;
	int len2;

/*	len = _printf("Let's try to printf a simple sentence.\n");
	printf("Number of characters printed: %d\n", len);
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("Number of characters printed: %d\n", len2);*/
	len = _printf("Character:[%c]\n", 'H');
	printf("Number of characters printed: %d\n", len);
	printf("Character:[%c]\n", 'H');
	len = _printf("String:[%s]\n", "I am a string !");
	printf("Number of characters printed: %d\n", len);
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	printf("Number of characters printed: %d\n", len);
	len2 = printf("Percent:[%%]\n");
	printf("Number of characters printed: %d\n", len2);
return (0);
}
