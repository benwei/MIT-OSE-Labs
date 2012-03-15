// Simple command-line kernel monitor useful for
// controlling the kernel and exploring the system interactively.

#include <inc/stdio.h>
#include <inc/string.h>
#include <inc/memlayout.h>
#include <inc/assert.h>
#include <inc/x86.h>

#include <kern/console.h>
#include <kern/monitor.h>
#include <kern/kdebug.h>

#define CMDBUF_SIZE	80	// enough for one VGA text line


struct Command {
	const char *name;
	const char *desc;
	// return -1 to force monitor to exit
	int (*func)(int argc, char** argv, struct Trapframe* tf);
};

static int
mon_octal(int argc, char **argv, struct Trapframe *tf);

int
mon_backtrace(int argc, char **argv, struct Trapframe *tf);

static struct Command commands[] = {
	{ "backtrace", "Display callbacks", mon_backtrace},
	{ "help", "Display this list of commands", mon_help },
	{ "octal", "Display octal", mon_octal},
	{ "kerninfo", "Display information about the kernel", mon_kerninfo },
};
#define NCOMMANDS (sizeof(commands)/sizeof(commands[0]))

unsigned read_eip();

/***** Implementations of basic kernel monitor commands *****/
int
mon_octal(int argc, char **argv, struct Trapframe *tf)
{
	int i;
	if (argc < 2) {
		cprintf("syntax: octal <Decimal>\n");
		return 0;
	}
	unsigned int num = strtol(argv[1], NULL, 10);
	cprintf("octal(%u)=%o(o)\n", num, num);
	return 0;
}

int
mon_help(int argc, char **argv, struct Trapframe *tf)
{
	int i;

	for (i = 0; i < NCOMMANDS; i++)
		cprintf("%s - %s\n", commands[i].name, commands[i].desc);
	return 0;
}

int
mon_kerninfo(int argc, char **argv, struct Trapframe *tf)
{
	extern char entry[], etext[], edata[], end[];

	cprintf("Special kernel symbols:\n");
	cprintf("  entry  %08x (virt)  %08x (phys)\n", entry, entry - KERNBASE);
	cprintf("  etext  %08x (virt)  %08x (phys)\n", etext, etext - KERNBASE);
	cprintf("  edata  %08x (virt)  %08x (phys)\n", edata, edata - KERNBASE);
	cprintf("  end	%08x (virt)  %08x (phys)\n", end, end - KERNBASE);
	cprintf("Kernel executable memory footprint: %dKB\n",
		(end-entry+1023)/1024);
	return 0;
}

#define J_NEXT_EBP(ebp) (*(uint *)ebp)
#define J_ARG_N(ebp, n) (*(uint *)(ebp + n))

extern unsigned int bootstacktop;
typedef unsigned int uint;
static struct Eipdebuginfo info = {0};
static inline uint*
dump_stack(uint *p)
{
	uint i;
	cprintf("ebp=%08x  eip=%08x args", p, J_ARG_N(p, 1));
	for (i=2; i < 7; i++) {
		cprintf(" %08x",J_ARG_N(p,i)); 
	}

	memset(&info, 0, sizeof(info));
	debuginfo_eip((uintptr_t)*(p+1), &info);
	cprintf("\n");
	return (uint *)J_NEXT_EBP(p);
}
int
mon_backtrace(int argc, char **argv, struct Trapframe *tf)
{
	uint *p = (uint *) read_ebp();
	uint eip = read_eip();	
	cprintf("current eip=%08x", eip);
	debuginfo_eip((uintptr_t) eip, &info);
	cprintf("\n");
	do {
		p = dump_stack(p);
	} while(p); // && *p != 0);

	return 0;
}



/***** Kernel monitor command interpreter *****/

#define WHITESPACE "\t\r\n "
#define MAXARGS 16

static int
runcmd(char *buf, struct Trapframe *tf)
{
	int argc;
	char *argv[MAXARGS];
	int i;

	// Parse the command buffer into whitespace-separated arguments
	argc = 0;
	argv[argc] = 0;
	while (1) {
		// gobble whitespace
		while (*buf && strchr(WHITESPACE, *buf))
			*buf++ = 0;
		if (*buf == 0)
			break;

		// save and scan past next arg
		if (argc == MAXARGS-1) {
			cprintf("Too many arguments (max %d)\n", MAXARGS);
			return 0;
		}
		argv[argc++] = buf;
		while (*buf && !strchr(WHITESPACE, *buf))
			buf++;
	}
	argv[argc] = 0;

	// Lookup and invoke the command
	if (argc == 0)
		return 0;
	for (i = 0; i < NCOMMANDS; i++) {
		if (strcmp(argv[0], commands[i].name) == 0)
			return commands[i].func(argc, argv, tf);
	}
	cprintf("Unknown command '%s'\n", argv[0]);
	return 0;
}

void
monitor(struct Trapframe *tf)
{
	char *buf;

	cprintf("Welcome to the JOS kernel monitor!\n");
	cprintf("Type 'help' for a list of commands.\n");


	while (1) {
		buf = readline("K> ");
		if (buf != NULL)
			if (runcmd(buf, tf) < 0)
				break;
	}
}

// return EIP of caller.
// does not work if inlined.
// putting at the end of the file seems to prevent inlining.
unsigned
read_eip()
{
	uint32_t callerpc;
	__asm __volatile("movl 4(%%ebp), %0" : "=r" (callerpc));
	return callerpc;
}
