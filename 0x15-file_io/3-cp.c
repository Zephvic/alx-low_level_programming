#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * error_exit - Print error message and exit with specified code.
 * @code: Exit code.
 * @msg: Error message to print.
 */
void error_exit(int code, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * main - Copy the content of one file to another.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	int source_fd, dest_fd;
	ssize_t n;
	char buf[1024];

	if (ac != 3)
		error_exit(97, "Usage: cp file_from file_to");

	source_fd = open(av[1], O_RDONLY);
	if (source_fd == -1)
		error_exit(98, "Error: Can't read from file");

	dest_fd = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (dest_fd == -1)
		error_exit(99, "Error: Can't write to file");

	while ((n = read(source_fd, buf, sizeof(buf))) > 0)
	{
		if (write(dest_fd, buf, n) != n)
			error_exit(99, "Error: Can't write to file");
	}

	if (n == -1)
		error_exit(98, "Error: Can't read from file");

	if (close(source_fd) == -1)
		error_exit(100, "Error: Can't close fd");
	if (close(dest_fd) == -1)
		error_exit(100, "Error: Can't close fd");

	return (0);
}

