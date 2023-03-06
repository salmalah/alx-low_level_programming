#include "main.h"
/**
 * _strspn - a function that gets the length of a prefix substring.
 * @s: an input string
 * @accept: an input character with to locate into string s
 * Return: returns pointer to c position
 */
unsigned int _strspn(char *s, char *accept)
{
	int count;
	bool found;

	count = 0;
	while (*s != '\0')
	{
		found = false;
		while (accept != '\0')
		{
			if (accept == s)
			{
				found = true;
				break;
				count++;
			}
			accept++;
		}
		s++;
		if (found == true)
			break;
	}
	return (count);
}
