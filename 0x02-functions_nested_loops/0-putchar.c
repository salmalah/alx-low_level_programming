#include "main.h"
/**
 * main - This is the starting of the program
 *
 * Description : prints putchar fonction
 *
 *Return: 0 if successfull else 1
 */
int main(void)
{
	int word[8] = {95, 112, 117, 116, 99, 104, 97, 114};
	int i;

	for (i = 0; i < 8; i++)
	{
		_putchar(word[i]);
	}
	_putchar('\n');
	return (0);
}
