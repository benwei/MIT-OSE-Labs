#include <stdio.h>
/*
while you compile on mac osx Lion with __asm__, if you don't apply with
-fasm-blocks, you will see following error.
  inlineasm.c:9: error: asm blocks not enabled, use `-fasm-blocks' before ‘;’ token
*/

#define __asm__ asm

int swap(int a, int b) {
        printf("before a=%d, b=%d\n", a, b);

        __asm__ __volatile__(
        "movl %1, %%eax\t\n"
        "movl %0, %%ebx\t\n"
        "movl %%eax, %0\t\n"
        "movl %%ebx, %1\t\n"
        :"=r" (a),"=r"(b) /* output */
	/* change 'r' to '0'/'1' for cygwin build testing */
        :"0" (a),"1"(b)
        :"%eax", "%ebx"
        ); /* input */

        printf("after  a=%d, b=%d\n", a, b);
}

int main()
{
        int a = 1 , b=2;
        swap(a, b);
        return 0;
}
