#include <stdio.h>

int gi = 10;
unsigned char guc = 20;
short gs = -25;

int f();
int g(int x1, int x2, int x3, int x4);

int main() {
   gi = f(40000, 300, 300, 52);
   printf("gi = %d\tgc=%d\tgs=%d\n", gi, guc, gs);
   return 0;
}

int f() {
    _asm{
	   // allocate local variables
	   sub  esp, 16

	   // lc1 = ps1 + puc1;
	   movsx  eax, WORD PTR[ebp + 8] // ps1
	   movzx  ecx, BYTE PTR[ebp + 12] // puc1
	   add  eax, ecx
	   mov BYTE PTR[ebp - 1], al  // lc1

	   //li1 = pc1 * 2;
	     // to "* 2", use shift 1 bit to the left operation
	     // i.e., shl eax, 1
	   movsx   eax, BYTE PTR [ebp + 16]   // pc1
	   shl   eax, 1
	   mov   DWORD PTR [ebp - 8], eax  // li1

	   // ls1 = guc - ps1;
	   movzx  eax, BYTE PTR guc    // guc
	   movsx   ecx, WORD PTR [ebp + 8]  // ps1
	   sub  eax, ecx
	   mov   WORD PTR [ebp - 10], ax  // ls1

           // lus1 = gs + gi + 12;
//	   movsx  eax, WORD PTR gs  // gs
	   add    eax, DWORD PTR gi // gi
	   add    eax, 12
	   mov    WORD PTR [ebp - 14], ax // lus1

	   //luc1 = g(lc1, li1, puc1, pi1+2);
	   mov   eax, DWORD PTR [ebp + 20] // pi1
	   add   eax, 2
	   push   eax
	   movzx   eax, BYTE PTR [ebp + 12] //puci
	   push   eax
	   mov    eax, DWORD PTR [ebp - 8] // li1
	   push  eax
	   movsx   eax, BYTE PTR [ebp - 1]  // lc1
	   push  eax
	   call   g
	   add   esp, 16

	   // gi += (luc1 - li1);
	   mov  eax, DWORD PTR gi  // gi
	   movzx   ecx, BYTE PTR[ebp - 11] // luc1
	   sub  ecx, DWORD PTR[ebp - 8] // li1
	   add  eax, ecx
	   mov   DWORD PTR gi, eax  // gi

	   	// return gi + ls1 - luc1;
	   mov  eax, DWORD PTR gi // gi
	   movsx  ecx, WORD PTR [ebp - 10] // ls1
	   add eax, ecx
	   movzx  ecx, BYTE PTR[ebp - 11] // luc1
	   sub  eax, ecx

	   // deallocate local variables
	   mov   esp, ebp
    }
}

int g(int x1, int x2, int x3, int x4) {
   guc = x1 - x3 + gs;
   return gs + x2 - x4;
}
