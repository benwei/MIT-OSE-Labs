#include <stdio.h>
#define times3(arg1, arg2) \
asm( \
  "leal (%0,%0,2),%0" \
  : "=r" (arg2) \
  : "0" (arg1) );

#define times5(arg1, arg2) \
asm( \
  "leal (%0,%0,4),%0" \
  : "=r" (arg2) \
  : "0" (arg1) );

#define times9(arg1, arg2) \
asm( \
  "leal (%0,%0,8),%0" \
  : "=r" (arg2) \
  : "0" (arg1) );

#define msg(t, a, b) \
	printf("times%d(%d)=>%d\n", t, a, b);

int main()
{
	int a = 2; int b=0;
	times3(a, b);
	msg(3, a, b);
	times5(a, b);
	msg(5, a, b);
	times9(a, b);
	msg(9, a, b);
	return 0;
}

