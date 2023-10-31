#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file to append to.
 * @text_content: NULL-terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_status;
	ssize_t len = 0;

	if (filename == NULL)
	return (-1);

	if (text_content == NULL)
		return (1);

	while (text_content[len])
		len++;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	write_status = write(fd, text_content, len);
	close(fd);

	if (write_status == -1)
		return (-1);

	return (1);
}
