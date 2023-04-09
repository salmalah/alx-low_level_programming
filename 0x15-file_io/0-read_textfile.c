#include <unistd.h>
#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
/**
 * read_textfile - a function that reads a text
 * file and prints it to the POSIX standard output
 * @filename: file will be open
 * @letters: The number of letters
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fl, bytes_r, total_r;
	char *buff;

	buff = malloc(letters);
	if (buff == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	fl = open(filename, O_RDONLY);

	if (fl == -1)
	{
		free(buff);
		return (0);
	}

	bytes_r = read(fl, buff, letters);

	total_r = write(STDOUT_FILENO, buff, bytes_r);

	close(fl);

	return (total_r);
}
