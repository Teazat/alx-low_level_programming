#include "main.h"

/**
 * create_file - Creates a file and writes content to it
 * @filename: Name of the file to create
 * @text_content: Content to write into the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content)
	{
		while (text_content[length])
			length++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);

	if (text_content)
	{
		write_status = write(file_descriptor, text_content, length);
		if (write_status == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor);
	return (1);
}
