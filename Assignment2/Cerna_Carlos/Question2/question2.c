#include <stdio.h>

int f();
int g();

int x, y;

int main() {
	/* int main(int argc, char **argv, char **envp) {
		int i, j;
		j = 0;

		for(i = 10 ; i < 30; i++) {
			if (i < 20) {
				j += i;
			}
			else {
				j -= i;
			}
		 }
		 x = i;
		 y = j;
	*/

	_asm {
		//stack pointer limit of 8 bytes
		sub  esp, 8

		mov DWORD PTR[ebp - 8], 0 //set j as 0
		mov DWORD PTR[ebp - 4], 10 // set i as 10
		jmp L1 //enter loop
		L1:
			mov eax, DWORD PTR[ebp - 4] // set eax as i
			cmp eax, 30 // compare i < 30
			jl L2 // jump if true
			mov eax, DWORD PTR[ebp - 4]
			mov x, eax // x = i
			mov eax, DWORD PTR[ebp - 8]
			mov y, eax // y = j error
			ret
		L2:
			mov eax, DWORD PTR[ebp - 4] //store i in eax
			cmp eax, 20 // compare i < 20
			jl L3
			mov eax, DWORD PTR[ebp - 8] // j -= i
			sub eax, DWORD PTR[ebp - 4]
			mov DWORD PTR[ebp - 8], eax
			jmp L1
		L3:
			mov eax, DWORD PTR[ebp - 8] // j += i
			add eax, DWORD PTR[ebp - 4]
			mov DWORD PTR[ebp - 8], eax
			jmp L1

	    // deallocate local variables
		mov esp, ebp
	}
	printf("x = %d\ty = %d\n", x, y);
	getchar();
}