#include "main.h"
/**
 * read_textfile - a function that reads a text
 * file and prints it to the POSIX standard output
 * @filename: file will be open
 * @letters: The number of letters
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int ffd;
	char *buff;
	ssize_t total_r = 0, bytes_r, bytes_writ;

	if (!filename)
		return (0);
	ffd = open(filename, O_RDONLY);
	if (ffd == -1)
		return (0);
	*buff = malloc(letters);
	if (!buff)
	{
		close(ffd);
		return (0);
	}
	while ((bytes_r = read(ffd, buff, letters)) > 0)
	{
		bytes_writ = write(STDOUT_FILENO, buff, bytes_r);
		if (bytes_writ == -1 || bytes_writ != bytes_r)
		{
			free (buff);
			close (ffd);
			return (0);
		}
		total_r += bytes_r;
		if (total_r >= letters)
		{
			break;
		}
	}
	free (buff);
	close (ffd);
	if ( bytes_r == -1)
		return (0);
	return total_r;
}

