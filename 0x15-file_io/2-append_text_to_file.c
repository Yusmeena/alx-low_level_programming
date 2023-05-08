#include "main.h"

/**
* a function that append_text_to_file - appends text at the end of a file
* @filename: filename
* @text_content: added content
*
* Return: 1 if the exist. -1 if the file does not exists
* or if fails.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int file;
	int letters;
	int rwr;

	if (!filename)
		return (-1);

	file = open(filename, O_WRONLY | O_APPEND);

	if (file == -1)
		return (-1);

	if (text_context)
	{
		for (letters = 0; text_content[letters]; letters++)
			;
	
	rwr = write(file, text_content, letters);

	if (rwr == -1)
		return (-1);
	}

	close(file);
}
