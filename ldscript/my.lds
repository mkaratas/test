OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64",
	      "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)
SEARCH_DIR("/usr/x86_64-linux-gnu/lib64"); SEARCH_DIR("=/usr/local/lib/x86_64-linux-gnu"); SEARCH_DIR("=/usr/local/lib64"); SEARCH_DIR("=/lib/x86_64-linux-gnu"); SEARCH_DIR("=/lib64"); SEARCH_DIR("=/usr/lib/x86_64-linux-gnu"); SEARCH_DIR("=/usr/lib64"); SEARCH_DIR("=/usr/local/lib"); SEARCH_DIR("=/lib"); SEARCH_DIR("=/usr/lib");

SECTIONS
{
	. = 0x10000;
	.text : {
		*(.text)
	}

	.=0x8000000;
	.data : {
		*(.data)
	}
	.bss : {
		*(.bss)
	}
}

