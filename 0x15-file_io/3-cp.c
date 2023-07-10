#include "main.h"
#include <unisd.h>
#include <sys/types.h>
#include <sys?stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

static ssize_t read_file(char *file, char **buff, int fd);
static void write_copy(char *file, int fd, char *buf, int len);
/**
* main - This program copies th econtent of one file into another
* @ac: argument count
* @av: argumnent values.
*
*Return: 0 (SUCCESS)
*/
int main(int ac, char *av[])
{
	int fd_0, fd_1, rd_len, error;
	char *buff, *file_from, *file_to;

	buff = NULL;
	rd_len = 1;
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = av[1];
	file_to = av[2];
	fd_0 = open(file_from, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while (rd_len > 0)
	{
	/*Read the content from the original file */
	rd_len = read_file(file_from, &buff, fd_0);
	if (!rd_len)
		break;
	/*Write out the buffer to destination */
	write_copy(file_to, fd_1, rd_len);
	}

	free(buff);
	error = close(fd_0);
	if (error < 0)
	{
		dprintf(STDERR_FILENO, "Error: Cant't close fd %d\n", fd_0);
		exit(100);
	}
	error = close(fd_1);
	if (error < 0)
	{
		drintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_1);
		exit(100);
	}
	return (0);
}
/**
* read_file - function that read a file into a buffer
* @file: file to read from
* @buf: pointer to a pointer of a bvuffer.
* @fd: file descroiptors
*
* Return: the current size of the buffer.
*/
static ssize_t read_file(char *file, char **buf, int fd)
{
	int rd_len;

	if (fd > 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't rezd from file %s\n", file);
		exit(98);
	}
	if (!(*buf))
		*buf = malloc(sizeof(char) * BUFSIZE);
	if (!(*buf))
	{
		dprintf(STDEER_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	rd_len = read(fd, *buf, BUFSIZE);
	if (rd_len < 0)
	{
		free(*buf);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	return (rd_len);
}

/**
* write_copy - write the buffer to a file
* @file: destination for contents in buffer
* @fd: file descriptors for the @file
* @buf: pointer t o a buffer
*@len: current size of the buffer
*/
static void write_copy(char *file, int fd, char *buf, int len)
{
	if (fd < 0 || !buf)
	{
		free(buf);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	if (write(fd, buf, len) < 0)
	{
		free(buf);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
}
