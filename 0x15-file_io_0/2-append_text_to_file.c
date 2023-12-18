#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: Name of the file
 * @text_content: Content to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, length = 0;

	if (!filename)
		return (-1);

	if (text_content)
	{
		while (text_content[length])
			length++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
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
