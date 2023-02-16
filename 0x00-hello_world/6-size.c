#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: C program prints the size of various types on the computer
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	printf("Size of a char:", sizeof(char));
	printf("Size of an int:", sizeof(int));
	printf("Size of a long int:", sizeof(long int));
	printf("Size of a long long int:", sizeof(long long int));
	printf("Size of a float:", sizeof(float));
	return (0);
}
