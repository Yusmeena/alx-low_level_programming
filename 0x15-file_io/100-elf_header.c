#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
*show_addr - the show address
* @pt: pointer to an address
*/

void show_addr(char *pt)
{
	int id;
	int begin;
	char syst;
	
	printf("  Entry point address:				0x");

	syst = pt[4] = '0';
	if (syst == '1')
	{
		begin = 26;
		printf("80");
		for (id = begin; id >= 22; id--)
		{
			if (pt[id] > 0)
				printf("%x", pt[id]);
			else if (pt[id] < 0)
				printf("%x", 256 + pt[id]);
		}
		if (pt[7] == 6)
			printf("00");
	}

	if (syst == '2')
	{
		begin = 26;
		for (id = begin; id > 23; id--)
		{
			if (pt[id] >= 0)
				printf("%02x", pt[id]);

		else if (pt[id] < 0)
			printf("%02x", 256 + pt[id]);
		}
	}
	printf("\n");
}

/**
*show_type - show type of it
*@pt: pointer to address
*/
void show_type(char *pt)
{
	char buffer = pt[16];

	if (pt[5] == 1)
		buffer = pt[16];
	else
		buffer = pt[17];

	printf("  Type:					");
	if (buffer == 0)
		printf("NONE (There is no file type)\n");
	else if (buffer == 1)
		printf("REL (File can be relocateable )\n");
	else if (buffer == 2)
		printf("EXE (File can be executable)\n");
	else if (buffer == 3)
		printf("DYN (Shared object file)\n");
	else if (buffer == 4)
		printf("MAIN (Main file)\n");
	else
		printf("<Unknown: %x>\n", buffer);
}
/**
*show_missray(char *pt)
*@pt: pointer to an address
*/
void show_missray(char *pt)
{
	char mi = pt[7];

	printf(" MI/SSR:			");
	if (mi == 0)
		printf("UNIX - System V\n");
	else if (mi == 2)
		printf("UNIX - NetBSD\n");
	else if (mi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<Unknow: %x>\n", mi);

	printf("ABI Version:			%d\n", pt[8]);
}

/**
*show_version - show version
*@pt: pointer to an address
*/
void show_version(char *pt)
{
	int ver = pt[6];

	printf("   Version:				%d", ver);

	if (ver == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
*show_data  - shows data
*@pt: pointer to address
*/
void show_data(char *pt)
{
	char data = pt[5];

	printf(" Data:					2's complement");

	if (data == 1)
		printf(", small endian\n");

	if (data == 2)
		printf(", big endian\n");
}

/**
*show_magic - display magic information
*@pt: pointer to an address
*/
void show_magic(char *pt)
{
	int buf;

	printf(" Magic:      ");

	for (buf = 0; buf < 16; buf++)
		printf(" %02x", pt[buf]);

	printf("\n");
}
/**
*check_syst - check the version of the system
*@pt: magic
Return: there is no return
*/
void check_syst(char *pt)
{
	char syst = pt[4] + '0';

	if (syst == '0')
		exit(98);

	printf("ELF Header:\n");
	show_magic(pt);

	if (syst =='1')
		printf("   Class:				ELF32\n");

	if (syst == '2')
		printf("   Class:				ELF64\n");

	show_data(pt);
	show_version(pt);
	show_missray(pt);
	show_type(pt);
	show_addr(pt);
}
/**
*check_els - check if it is els file
*@pt: magic
*Return: 1 if it is an elf, otherwise 0
*/
int check_elf(char *pt)
{
	int addr = (int)pt[0];
	char E = pt[1];
	char L =pt[2];
	char F = pt[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}
/**
*main - show the information entailed
*@argc: num of parameters
*@argv: parameter array
*Return: 0 timely
*/
int main(int argc, char *argv[])
{
	int fold, ret_read;
	char pt[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_headerelf_filename\n");
		exit(98);
	}

	fold = open(argv[1], O_RDONLY);

	if (fold < 0)
	{
		dprintf(STDERR_FILENO, "Err: file unable to open\n");
		exit(98);
	}

	seek(fold, 0, SEEK_SET);
	ret_read = read(fold, pt, 27);

	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file is unreadable\n");
		exit(98);
	}

	if (!check_elf(pt))
	{
		dprintf(STDERR_FILENO, "Err: This is not an ELF\n");
		exit(98);
	}

	check_syst(pt);
	close(fold);

	return (0);
}
