#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

char *create_buffer(char *file);
void close_fd(int fd);

/**
 * create_buffer - Allocate memory for a buffer.
 * @file: Name of the file buffer storing characters for.
 *
 * Return: A pointer to the allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buf = malloc(BUF_SIZE);

	if (!buf)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buf);
}

/**
 * close_fd - Closes a file descriptor.
 * @fd: The file descriptor to close.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy content from one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, or exit with one of the error codes.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_bytes, written_bytes;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buffer(argv[2]);
	fd_from = open(argv[1], O_RDONLY);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while ((read_bytes = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		written_bytes = write(fd_to, buf, read_bytes);

		if (fd_from == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}
		if (fd_to == -1 || written_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}
	}

	free(buf);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
