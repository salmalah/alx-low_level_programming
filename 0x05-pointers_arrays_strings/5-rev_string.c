#include <string.h>
#include <main.h>
/**
 * rev_string - a function that reverse a string
 * @s: an input string
 * Return: Nothing
 */
void rev_string(char *s)
{
	int i;
	int len = strlen(s);
	char rev;

	len = strlen(s);
	for (i = len - 1; i >= 0; i--)
	{
		rev = s[i];
		s[i] = rev;
	}
}
