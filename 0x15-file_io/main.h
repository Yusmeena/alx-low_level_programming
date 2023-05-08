#ifndef MAIN_H
# define MAIN_H

/*
*Header file that include function protypes for all functions
*in the 0x14 file_io directory or folder
* Written by Ojo Yusuf
* this file contain the necessary function prototypes for the
* for the functons used in i/o directory or folder
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
