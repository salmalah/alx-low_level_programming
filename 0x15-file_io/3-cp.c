#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd_from, fd_to;
    ssize_t num_read, num_written;
    char buffer[BUFFER_SIZE];

    // Check argument count
    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    // Open file_from for reading
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    // Open file_to for writing (truncate if it already exists)
    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }

    // Copy data from file_from to file_to
    while ((num_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        num_written = write(fd_to, buffer, num_read);
        if (num_written != num_read) {
            dprintf(STDERR_FILENO, "Error: Incomplete write to %s\n", argv[2]);
            exit(99);
        }
    }

    // Check for errors in read()
    if (num_read == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    // Close files and check for errors
    if (close(fd_from) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }
    if (close(fd_to) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return 0;
}
