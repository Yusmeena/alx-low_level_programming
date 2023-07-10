#include "main.h"
#include <stdlib.h>
/**
* read_textfile - reads a text file and displays the letters
* @filename: filename
* @letters: numbers of letter displayed
* Return: numbers of letters dispalyed. If fails, return 0.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int filed;
	ssize_t nrd, nwr;
	char *buff;

	if (!filename)
		return (0);

	filed = open(filename, O_RDONLY);

	if (filed == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	nrd = read(filed, buff, letters);
	nwr = write(STDOUT_FILENO, buff, nrd);

	close(filed);

	free(buff);

	return (nwr);
}
