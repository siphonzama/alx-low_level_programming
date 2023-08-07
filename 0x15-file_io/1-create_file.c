#include "main.h"

/**
 * create_file-a function that creates a file
 * @filename: a pointer to the name of the created file
 * @text_content: a pointer to a string to write the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int a, z, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	a = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	z = write(a, text_content, len);

	if (a == -1 || z == -1)
		return (-1);

	close(a);

	return (1);
}
