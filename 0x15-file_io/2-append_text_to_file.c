#include "main.h"
/**
* append_text_to_file - Apppends text at the end of file
* @filename: filename
* @text_content: added content
*
* Return: 1 if the exist. -1 if the file does not exits
* or if fails
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int filed;
	int letters;
	int rwr;

	if (!filename)
		return (-1);

	filed = open(filename, O_WRONLY | O_APPEND);

	if (filed == -1)
		return (-1);

	if (text_content)
	{
		for (letters = 0; text_content[letters]; letters++)
			;

		rwr = write(filed, text_content, letters);

		if (rwr == -1)
			return (-1);
	}
	close(filed);

	return (1);
}
