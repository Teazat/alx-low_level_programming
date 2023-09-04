#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Read text from a file and print to STDOUT.
 * @filename: The name of the text file being read.
 * @letters: The number of letters to be read.
 *
 * Return: The actual number of bytes read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd, w, t;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	t = read(fd, buf, letters);
	if (t == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, t);
	if (w == -1 || (size_t)w != (size_t)t)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);

	return (w);
}
