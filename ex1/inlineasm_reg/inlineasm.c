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
        "movl %1, %%eax;"
        "movl %0, %%ebx;"
        "movl %%eax, %0;"
        "movl %%ebx, %1"
        :"=r" (a),"=r"(b) /* output */
        :"r" (a),"r"(b)
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
