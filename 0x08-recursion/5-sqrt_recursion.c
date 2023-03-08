#include "main.h"
/**
 * _sqrt_recursion - It returns the value of square root of n
 * @n: an input integer
 * Return: The square root of n
 */
int _sqrt_recursion(int n)
{
	float temp, sqrt;

	sqrt = (n / 2);
	temp = 0;
	if (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (n / temp + temp) / 2;
		return (sqrt);
	}
	else 
		return (-1);
}
