#include "main.h"

/**
* create_file - creates a file
* @filename: filename.
* @text_content: content writed in the file.
*
* Return: 1 if it success, -1 if it fails.
*/
int create_file(const char *filename, char *text_content)
{
	int filed;
	int numletters;
	int rwr;

	if (!filename)
	return (-1);

	filed = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (filed == -1)
	return (-1);

	if (!text_content)
	text_content = "";

	for (numletters = 0; text_content[numletters]; numletters++)
		;

	rwr = write(filed, text_content, numletters);

	if (rwr == -1)
	return (-1);

	close(filed);

	return (1);
}
