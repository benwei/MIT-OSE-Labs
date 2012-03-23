
/* this code should run in real mode, otherwise you'll get coredump*/
int main()
{
	asm("cli");
	asm("sti");
	return 0;
}
