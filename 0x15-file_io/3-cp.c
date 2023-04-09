#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>

int close_file(int);
/**
 * main - a main function
 * @argc: arguments passed
 * @argv: pointers to array
 * Return: 1 on success, exits on failure
 */
int main(int argc, char *argv[])
{
	int bytes_r = 0, _EOF = 1, from_fl = -1, to_fl = -1, err_or = 0;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fl = open(argv[1], O_RDONLY);
	if (from_fl < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	to_fl = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (to_fl < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(from_fl);
		exit(99);
	}

	while (_EOF)
	{
		_EOF = read(from_fl, buff, 1024);
		if (_EOF < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close_file(from_fl);
			close_file(to_fl);
			exit(98);
		}
		else if (_EOF == 0)
			break;
		bytes_r += _EOF;
		err_or = write(to_fl, buff, _EOF);
		if (err_or < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file(from_fl);
			close_file(to_fl);
			exit(99);
		}
	}
	err_or = close_file(to_fl);
	if (err_or < 0)
	{
		close_file(from_fl);
		exit(100);
	}
	err_or = close_file(from_fl);
	if (err_or < 0)
		exit(100);
	return (0);
}

/**
 * close_file - A function closes a file
 * @des_error: Description error for closed file
 * Return: 1 on successful else -1
 */
int close_file(int des_error)
{
	int err;

	err = close(des_error);
	if (err < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", des_error);
	return (err);
}
