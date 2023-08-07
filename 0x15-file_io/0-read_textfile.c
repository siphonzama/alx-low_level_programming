#include "main.h"

/**
 * read_textfile-a function that reads a text file and prints it to the POSIX
 * @filename: the file to be read
 * @letters: the number of letters being read
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t tf;
	char *temp;
	ssize_t a;
	ssize_t z;

	tf = open(filename, O_RDONLY);
		if (tf == -1)
			return (0);
	temp = malloc(sizeof(char) * letters);
	z = read(tf, temp, letters);
	a = write(STDOUT_FILENO, temp, z);

	free(temp);
	close(tf);
	return (a);
}
