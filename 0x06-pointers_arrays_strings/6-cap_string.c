#include "main.h"
#include <string.h>
/**
 * cap_string - a function that capitalizes all words of a string
 * @s: an input string
 * Return: pointer to s
 */
char *cap_string(char *s)
{
        int len;
        int i;
	char seperators[13] = { ' ', '\t', '\n', ',', ';', '.', '!', '?','"', '(', ')', '{', '}' };

        len = strlen(s);
        for (i = 0; i < len; i++)
        {
                if (s[i] >= 'a' && s[i] <= 'z')
                        s[i] -= 32;
		if (seperators == s[i] && (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				s[i + 1] -= 32;
        }
        return (s);
}
