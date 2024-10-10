#include "main.h"
#include <math.h>
#include <stdio.h>
/**
 *
 * 
 *
 *
 */
void print_number(int n)
{
	int i = 0, j = 0;
	int arr[10] = {-9999};
	for (i = 0;  n >= 1 ; i++)
	{
		arr[i] = (n % 10);
		n = ceil(n / 10);
	}
	j = i - 1;
	while (j >= 0)
	{
		_putchar(arr[j] + '0');
		j--;
	}
	/*_putchar(n + '0');*/
	_putchar('\n');
}
