#include <stdio.h>
/**
 * main - A program that multiplies two numbers
 * @argc: The arguments' counter
 * @argv: The arguments' values
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int N1 , N2, result;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	result = argv[1] * argv[2];
	printf("%d\n", result);
	return (0);
}
