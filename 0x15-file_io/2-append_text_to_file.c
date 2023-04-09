#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/uio.h>
#include <fcntl.h>

/**
 * append_text_to_file - A function that appends text at the end to the file
 * @filename: the file to open
 * @text_content: The text to add
 * Return: 1 on successful else  -1 if the file can not be created
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int flo, fl_write, lent = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	flo = open(filename, O_RDWR | O_APPEND);
	if (flo < 0)
		return (-1);
	if (text_content == NULL)
	{
		close(flo);
		return (1);
	}

	while (*(text_content + lent))
		lent++;

	fl_write = write(flo, text_content, lent);
	close(flo);
	if (fl_write < 0)
	{
		return (-1);
	}

	return (1);
}
