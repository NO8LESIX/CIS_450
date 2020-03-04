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
    _asm{
		// complete your code here
		//create stack frame
		push ebp
		push mov ebp, esp

		mov eax, WORD PTR[ebp - 4] // eax <- ps1
		mov eax, BYTE PTR[ebp - 8] // eax <- puc1
		mov eax, BYTE PTR[ebp - 12] // eax <- pc1
		mov eax, DWORD PTR[ebp - 16] // eax <- pi1



		//luc1 = g(lc1, li1, puc1, pi1+2);
		mov eax, DWORD PTR[ebp + 20] // pi1
		add eax, 2
		push eax
		movzx eax, BYTE PTR[ebp + 12] //puci
		push eax
		mov eax, DWORD PTR[ebp - 8] // li1
		push eax
		movsx eax, BYTE PTR[ebp - 1] // lc1
		push eax
		call g
		add esp, 16
		mov BYTE PTR[ebp - 11], al // ulc1

		// lc1 = ps1 + puc1;
		movsx eax, WORD PTR[ebp + 8] // ps1
		movzx ecx, BYTE PTR[ebp + 12] // puc1
		add eax, ecx
		mov BYTE PTR[ebp - 1], al // lc1

		//luc1 = pi1 + 100;
		movsx eax, WORD PTR pi1 // gs
		add eax, 100
		mov WORD PTR[ebp - 14], ax // luc1

		//lus1 = gs + gi + 12;
		movsx eax, WORD PTR gs // gs
		add eax, DWORD PTR gi // gi
		add eax, 12
		mov WORD PTR[ebp - 14], ax // lus1


		// destroy the stack frame
		mov esp, ebp
		pop ebp
		ret

	}
}

int g(int x1, int x2, int x3, int x4) {
	printf("x1 = %d\tx2 = %d\tx3 = %d\tx4 = %d\n", x1, x2, x3, x4);
	gi = x1 - x3;
	return gi + x2 - x4;
}


