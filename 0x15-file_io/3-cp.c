#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - Print an error message and exit with a specified status code.
 * @status: The exit status code.
 * @msg: The error message to print.
 */
void error_exit(int status, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(status);
}

/**
 * copy_file - Copy the content of one file to another.
 * @src: Source file name.
 * @dest: Destination file name.
 */
void copy_file(const char *src, const char *dest)
{
	int src_fd, dest_fd;
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];

	src_fd = open(src, O_RDONLY);
	if (src_fd == -1)
		error_exit(98, "Error: Can't read from file");

	dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_fd == -1)
	error_exit(99, "Error: Can't write to file");

	while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(dest_fd, buffer, bytes_read) == -1)
			error_exit(99, "Error: Can't write to file");
	}

	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file");

	if (close(src_fd) == -1 || close(dest_fd) == -1)
	error_exit(100, "Error: Can't close file descriptor");
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	copy_file(argv[1], argv[2]);

	return (0);
}
