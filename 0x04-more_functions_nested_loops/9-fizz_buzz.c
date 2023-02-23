#include <stdio.h>
/**
 * main - Check code
 * Description: Is a “Fizz-Buzz test
 * Return: Always 0
 */

int main(void)
{
	int i;

	for (i = 1 ; i <= 100 ; i++)
	{
		if (i % 3 == 0)
		{
			printf("Fizz ");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz ");
		}
		else
			printf("%d ", i);
	}
	printf("\n");
	return (0);
}
