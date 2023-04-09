#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
/**
 * create_file - a function that creates a file
 * @filename: file name
 * @text_content: text
 * Return: 1 if successful else -1
 */
int create_file(const char *filename, char *text_content)
{
	int lent = 0, fl, in_lent = 0;
	char *pt;

	if (filename == NULL)
		return (-1);

	fl = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fl == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (in_lent = 0, pt = text_content; *pt; pt++)
			in_lent++;
		lent = write(fl, text_content, in_lent);
	}

	if (close(fl) == -1 || in_lent != lent)
		return (-1);
	return (1);
}
