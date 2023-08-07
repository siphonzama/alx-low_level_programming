#include "main.h"

/**
 * append_text_to_file-a function that appends text at the end of a file
 * @filename: a pointer to the file name
 * @text_content: the string to add at end
 *
 * Return: -1 if flename is NULL, 1 if the file exists and -1 if not
 */

int append_text_to_file(const char *filename, char *text_content)
{

	int a, z, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;

	}

	a = open(filename, O_WRONLY | O_APPEND);
	z = write(a, text_content, len);

	if (a == -1 || z == -1)
		return (-1);

	close(a);
	return (1);
}
