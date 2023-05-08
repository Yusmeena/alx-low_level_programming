#include "main.h"

/**
* read_textfile - reads a text file and displays the letters
*@filename: filename
*@letters: numbers of letter displayed.
*
* Return: numbers of letters displayed. if fails, return 0.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int filed;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	filed = open(filename, 0_RDONLY);

	if (filed == -1)
		return (0);

	buff = malloc(sizeof(char) * numletters);
	if (!buf)
		return (0);

	nrd = read(filed, buff, numletters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(filed);

	free(buf);

	return (nwr);
}
