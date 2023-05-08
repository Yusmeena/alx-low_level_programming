#include "main.h"
#include <stdlib.h>

/**
* read_textfile - reads a text file and displays the letters
*@filename: filename
*@letters: numbers of letter displayed.
*
* Return: numbers of letters displayed. if fails, return 0.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	ssize_t nrd, nwr;
	char *buff;

	if (!filename)
		return (0);

	file = open(filename, 0_RDONLY);

	if (file == -1)
		return (0);

	buff = malloc(sizeof(char) * numletters);
	if (!buff)
		return (0);

	nrd = read(filed, buff, numletters);
	nwr = write(STDOUT_FILENO, buff, nrd);

	close(file);

	free(buff);

	return (nwr);
}
