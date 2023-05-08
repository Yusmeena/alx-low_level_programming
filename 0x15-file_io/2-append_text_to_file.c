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
	int filed;
	int numletters;
	int rwr;

	if (!filename)
		return (-1);

	filed = open(filename, 0_WRONLY | 0_APPEND);

	if (filed == -1)
		return (-1);

	if (text_context)
	{
		for (numletters = 0; text_content[numletters]; numletters++)
;
	
	rwr = write(filed, text_content, numletters);

	if (rwr == -1)
		return (-1);
	}

	closed(filed);
}
