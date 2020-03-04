#include <stdio.h>

int gi;

int f();
int g();


int main() {


	gi = f(10, 132, 132, 56);

	printf("gi = %d\n", gi);

	return 0;
}

int f() {
	/* int f(short ps1, unsigned char puc1, char pc1, int pi1) {
		short ls1;
		unsigned char luc1;
		char lc1;
		int li1;

		ls1 = g(ps1, puc1, pc1, pi1);

		li1 = pc1 + pi1;

		luc1 = pi1 + 100;

		lc1 = li1 + ls1 + luc1;

		return gi + ls1 - luc1 - lc1; */
	_asm {
		// complete your code here
		sub  esp, 16

		//luc1 = g(lc1, li1, puc1, pi1);
		mov   eax, DWORD PTR[ebp + 20] // pi1
		push   eax
		movzx   eax, BYTE PTR[ebp + 12] //puc1
		push   eax
		mov    eax, DWORD PTR[ebp - 16] // li1
		push  eax
		movsx   eax, BYTE PTR[ebp - 12]  // lc1
		push  eax
		call   g
		add   esp, 16

		// li1 = pc1 + pi1;
		movsx  eax, BYTE PTR[ebp + 16] // pc1
		add  eax, DWORD PTR[ebp + 20] // pi1
		mov DWORD PTR[ebp - 16], eax  // li1

		//luc1 = pi1 + 100;
		mov   eax, DWORD PTR[ebp + 20]   // pi1
		add   eax, 100
		mov   BYTE PTR[ebp - 8], al  // luc1 error

		//lc1 = li1 + ls1 + luc1;
		mov eax, DWORD PTR[ebp - 16] // li1
	    movsx  ecx, WORD PTR[ebp - 1] // ls1
		add  eax, ecx
	    movzx  ecx, BYTE PTR[ebp - 8] // luc1
	    add  eax, ecx
	    mov BYTE PTR[ebp - 12], al  // lc1

	    // return gi + ls1 - luc1 - lc1;
	    mov  eax, DWORD PTR gi // gi
	    movsx  ecx, WORD PTR[ebp - 10] // ls1
	    add eax, ecx
	    movzx  ecx, BYTE PTR[ebp - 8] // luc1
	    sub  eax, ecx
		movzx  ecx, BYTE PTR[ebp - 12] // lc1
		sub  eax, ecx
	}
}

int g(int x1, int x2, int x3, int x4) {
	printf("x1 = %d\tx2 = %d\tx3 = %d\tx4 = %d\n", x1, x2, x3, x4);
	gi = x1 - x3;
	return gi + x2 - x4;
}


