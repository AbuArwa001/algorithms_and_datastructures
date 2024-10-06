#include "main.h"

/**
 * print_product - prints product according to its size
 * @prod: the number to be printed
 * @j: current column index
 * @n: size of the times table
 */
void print_product(int prod, int j, int n)
{
	if (prod > 99) /* 3-digit number */
	{
		_putchar(prod / 100 + '0');
		_putchar((prod / 10) % 10 + '0');
		_putchar(prod % 10 + '0');
	}
	else if (prod > 9) /* 2-digit number */
	{
		_putchar(' ');
		_putchar(prod / 10 + '0');
		_putchar(prod % 10 + '0');
	}
	else /* 1-digit number */
	{
		_putchar(' ');
		_putchar(' ');
		_putchar(prod + '0');
	}

	if (j < n) /* Add comma and spaces unless it's the last number in the row */
	{
		_putchar(',');
		_putchar(' ');
	}
}

/**
 * print_times_table - prints times table greater than 0
 *                     and less than or equal to 15
 * @n: size of the times table to be printed
 */
void print_times_table(int n)
{
	int i, j = 0;

	if (n > 15 || n < 0)
		return;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			int prod = i * j;

			print_product(prod, j, n); /* Print the product */
		}
		_putchar('\n'); /* Print newline after each row */
	}
}
