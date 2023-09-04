#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define ERROR(msg) { perror(msg); exit(98); }
#define CHECK_ERROR(cond, msg) { if (cond) ERROR(msg); }

enum { ELF_HEADER_SIZE = sizeof(Elf64_Ehdr) };

void print_header_info(Elf64_Ehdr *header);

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	CHECK_ERROR(argc != 2, "Usage: elf_header filename");

	fd = open(argv[1], O_RDONLY);
	CHECK_ERROR(fd == -1, "Error: Can't open file");

	ssize_t bytes_read = read(fd, &header, ELF_HEADER_SIZE);
	CHECK_ERROR(bytes_read == -1, "Error: Can't read file");
	CHECK_ERROR(bytes_read != ELF_HEADER_SIZE, "Error: Invalid ELF file");

	close(fd);

	print_header_info(&header);

	return (0);
}

void print_header_info(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic: ");
	for (int i = 0; i < EI_NIDENT; i++) {
		printf("%02x", header->e_ident[i]);
		printf((i == EI_NIDENT - 1) ? "\n" : " ");
	}

	printf("  Class: ");
	switch (header->e_ident[EI_CLASS]) {
		case ELFCLASSNONE: printf("none\n");
		break;
		case ELFCLASS32:   printf("ELF32\n");
		break;
		case ELFCLASS64:   printf("ELF64\n");
		break;
		default:           printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}

	printf("  Data: ");
	switch (header->e_ident[EI_DATA]) {
		case ELFDATANONE:  printf("none\n");
		break;
		case ELFDATA2LSB:  printf("2's complement, little endian\n");
		break;
		case ELFDATA2MSB:  printf("2's complement, big endian\n");
		break;
		default:           printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
	}

	printf("  Version: %d", header->e_ident[EI_VERSION]);
	printf((header->e_ident[EI_VERSION] == EV_CURRENT) ? " (current)\n" : "\n");

	printf("  OS/ABI: ");
	switch (header->e_ident[EI_OSABI]) {
		case ELFOSABI_NONE:	printf("UNIX - System V\n");
		break;
		case ELFOSABI_HPUX:	printf("UNIX - HP-UX\n");
		break;
		case ELFOSABI_NETBSD:	printf("UNIX - NetBSD\n");
		break;
		case ELFOSABI_LINUX:	printf("UNIX - Linux\n");
		break;
		case ELFOSABI_SOLARIS:	printf("UNIX - Solaris\n");
		break;
		case ELFOSABI_IRIX:	printf("UNIX - IRIX\n");
		break;
		case ELFOSABI_FREEBSD:	printf("UNIX - FreeBSD\n");
		break;
		case ELFOSABI_TRU64:	printf("UNIX - TRU64\n");
		break;
		case ELFOSABI_ARM:	printf("ARM\n");
		break;
		case ELFOSABI_STANDALONE:	printf("Standalone App\n");
		break;
		default:	printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}

	printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("  Type: ");
	switch (header->e_type) {
		case ET_NONE:	printf("NONE (None)\n");
		break;
		case ET_REL:	printf("REL (Relocatable file)\n");
		break;
		case ET_EXEC:	printf("EXEC (Executable file)\n");
		break;
		case ET_DYN:	printf("DYN (Shared object file)\n");
		break;
		case ET_CORE:	printf("CORE (Core file)\n");
		break;
		default:	printf("<unknown: %x>\n", header->e_type);
	}

	printf("  Entry point address: %#lx\n", header->e_entry);
}
