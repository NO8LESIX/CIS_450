#include <stdio.h>
int f() {
	int i, j;  // i at [ebp - 4] and j at [ebp - 8]
	i = 10;
	j = 5;

/*	if (i < j) {
		i++;
	} else {
		j--'
	} */

	_asm {
		// if (i < j) {
		mov eax, DWORD PTR[ebp - 4]  // eax <- i
		cmp eax, DWORD PTR[ebp - 8]  // eax - j
		jge  SHORT L1				 // if (the result >= 0) jump to L1
				// in question2 in Assignment3, SHORT (8-bit displacement) should be enough
				// if you omit "SHORT", the compiler generates 32-bit displacement
		//   i++;
		mov eax, DWORD PTR[ebp - 4]  // eax <- i
		add eax, 1					 // eax <- eax + 1
		mov DWORD PTR[ebp - 4], eax  // i <- eax
		// }
		jmp SHORT L2
		// else {
	    //    j--;
	L1: mov eax, DWORD PTR[ebp - 8]  // eax <- j
	    // Note
	    // L1:
	    //   mov eax, DWORD PTR[ebp - 8]
	    // is ok, too
		sub eax, 1					// eax <- eax - 1
		mov DWORD PTR[ebp - 8], eax  //  j <- eax
		// }
	L2:
	}
	printf("i = %d\tj = %d\n", i, j);
}

int main() {
	f();
}