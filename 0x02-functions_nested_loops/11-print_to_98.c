#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - Check description
 * @n: input number
 * Description: It a function that prints all natural numbers from n to 98
 * Return : 0 if seccussful else 1
 */
void print_to_98(int n)
{
	int counter;
	
	if (n <= 98)
	{
		for(counter = n; counter <= 98; counter++)
		{
			printf("%d", n);
			if (n == 98)
				continue;
			printf(", ");
		}
		printf("\n");
	}
	else
	{
		for(counter = n; counter >= 98; counter--)
		{
			printf("%d \n", counter);
			if (n == 98)
				continue;
			printf(", ");
		}
		printf("\n");
	}

}
