#include "main.h"
#include <string.h>
/**
 * _strcpy - a function that copies the string pointer
 * @dest: A pointer to destination of string
 * @src: A pointer to source string to copy from
 */
char *_strcpy(char *dest, char *src)
{
	dest = strcpy(dest, src);
	return (dest);

}
