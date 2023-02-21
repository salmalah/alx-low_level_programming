#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int t0 = 0, t1 = 1, s;

	int i;

	for (i = 1; i <= 93; i++)
	{
		s = t0 + t1;
		if (i != 93)
		{
			printf("%lu, ", s);
		}
		else
		{
			printf("%lu\n", s);
		}
		t0 = t1;
		t1 = s;
	}
	return (0);
}
