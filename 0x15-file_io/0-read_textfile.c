#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads and prints a text file to the POSIX standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	char *buf = malloc(letters);

	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	ssize_t bytes_read = read(fd, buf, letters);

	if (bytes_read == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}

	ssize_t bytes_written = write(STDOUT_FILENO, buf, bytes_read);

	if (bytes_written == -1 || (size_t)bytes_written != (size_t)bytes_read)
	{
		close(fd);
		free(buf);
		return (0);
	}

	close(fd);
	free(buf);

	return (bytes_written);
}

