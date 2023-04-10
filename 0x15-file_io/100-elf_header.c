#include <sys/types.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void print_magiic(unsigned char *e_ident);
void printd_ata(unsigned char *e_ident);
void printc_lass(unsigned char *e_ident);
void check_elff(unsigned char *e_ident);
void printv_ersiion(unsigned char *e_ident);
void print_abii(unsigned char *e_ident);
void print_osabii(unsigned char *e_ident);
void printty_ype(unsigned int x_type, unsigned char *e_ident);
void printE_ntry(unsigned long int y_entry, unsigned char *e_ident);
void close_elff(int elff);
/**
 * check_elff - Checks ELF file
 * @e_ident: A pointer containing the ELF magic numbers
 * Return: nothing
 */
void check_elff(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E'
				&& e_ident[i] != 'L' && e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_magiic - A function print the magic number ELf
 * @e_ident: pointer to an array containing ELF magic number
 * Return: nothing
 */
void print_magiic(unsigned char *e_ident)
{
	int in;

	printf("  Magic:   ");
	for (in = 0; in < EI_NIDENT; in++)
	{
		printf("%02x", e_ident[in]);
		if (in == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
			printf(" ");
	}
}
/**
 * printc_lass - A function print the class of an ELF
 * @e_ident: A pointer to an array
 * Return: nothing
 */
void printc_lass(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * printd_ata - Afunciotn prints the data of an ELF
 * @e_ident: A pointer to an array
 * Return: rien
 */
void printd_ata(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * printv_ersiion - A funciotn printf the version of an ELF
 * @e_ident: A pointer to an array
 * Return: nothing
 */
void printv_ersiion(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
 * print_osabii - A function print the OS/ABI of an ELF
 * @e_ident: A pointer to an array
 * Return: nothing
 */
void print_osabii(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abii - A funciotn print the ABI version of an ELF
 * @e_ident: A pointer to an array
 * Return: nothing
 */
void print_abii(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}
/**
 * printty_ype - A fucntion prints the type of an ELF
 * @x_type: The type of ELF
 * @e_ident: A pointer to an array
 * Return: nothing
 */
void printty_ype(unsigned int x_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		x_type >>= 8;
	printf("  Type:                              ");
	switch (x_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", x_type);
	}
}
/**
 * printE_ntry - A function prints the entry point of an ELF header
 * @y_entry: The address of the ELF entry point
 * @e_ident: A pointer to an array containing the ELF class
 */
void printE_ntry(unsigned long int y_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		y_entry = ((y_entry << 8) & 0xFF00FF00) | ((y_entry >> 8) & 0xFF00FF);
		y_entry = (y_entry << 16) | (y_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)y_entry);
	}
	else
	{
		printf("%#lx\n", y_entry);
	}
}
/**
 * close_elff - A function close an ELF file
 * @elff: The file descriptor of the ELF file
 * Return: nothinf
 */
void close_elff(int elff)
{
	if (close(elff) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elff);
		exit(98);
	}
}
/**
 * main - Displays the information contained in the ELF header
 * @argc: The number of arguments
 * @argv: An array of pointers to the arguments
 * Return: 0 on successful
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *head;
	int file, buff;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	head = malloc(sizeof(Elf64_Ehdr));
	if (head == NULL)
	{
		close_elff(file);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	buff = read(file, head, sizeof(Elf64_Ehdr));
	if (buff == -1)
	{
		free(head);
		close_elff(file);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elff(head->e_ident);
	printf("ELF Header:\n");
	print_magiic(head->e_ident);
	printc_lass(head->e_ident);
	printd_ata(head->e_ident);
	printv_ersiion(head->e_ident);
	print_osabii(head->e_ident);
	print_abii(head->e_ident);
	printty_ype(head->e_type, head->e_ident);
	printE_ntry(head->e_entry, head->e_ident);
	free(head);
	close_elff(file);
	return (0);
}

