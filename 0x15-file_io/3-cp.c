#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char *this_buffer(char *filename);
void endit_file(int endfile);

/**
*this_buffer - allocate 1024 bytes for buffer
*filename: name of the file storing the charater
*Return: buffer
*/
char *this_buffer(char *filename)
{
	char *create;

	create = malloc(sizeof(char) * 1024);

	if (create == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Won't write to %s\n", filename);
		exit(99);
	}

	return (create);
}

/**
*endit_file - file descrip close
* @endfile: descriptor to be close
*/
void endit_file(int endfile)
{
	int s;

	s = close(endfile);

	if (s == -1)
	{
		dprintf(STDERR_FILENO, "Error: won't close folde %d\n", endfile);
	}
}

/**
*main -duplicate a file to another file
*@argc: The numb of parameter
*@argv: Array of pointer to the parameter
*Return: 0 always
*/

int main(int argc, char *argv[])
{
	int begin, exe, rwt, wr;
	char *filename;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy file from file to\n");
		exit(97);
	}

	filename = this_buffer(argv[2]);
	begin = open(argv[1], O_RDONLY);
	rwt = read(begin, filename, 1024);
	exe = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (begin == -1 || rwt == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Won't read frm file %s\n", argv[1]);
			free(filename);
			exit(98);
		}

		wr = write(exe, filename, rwt);
		if (exe == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Won't write to %s\n", argv[2]);
			free(filename);
			exit(99);
		}

		rwt = read(begin, filename, 1024);
		exe = open(argv[2], 0_WRONLY | 0_APPEND);
	
	} while (rwt > 0);

	free(filename);
	end_file(begin);
	end_file(exe);

	return (0);
}
