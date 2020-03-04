#include <stdio.h>
int gg = 11;

int f(int x, int y, int gg) {
   return x + y + gg;
}

// g1: +8
// g2: +12
// x: -4
// y: -8

//int g(int g1, int g2) {
//   int x, y;
int g() {
    _asm {
      sub  esp, 8   // MM  since x, y are not referred to, 
		// area for them are not allocated automatically 
      mov  eax, DWORD PTR [ebp + 8]   // g1
      mov  DWORD PTR [ebp - 4], eax  // x
      mov  eax, DWORD PTR [ebp + 12]  // g2
      mov  DWORD PTR [ebp - 8], eax  // y
      mov eax, DWORD PTR gg    // gg
      add eax, DWORD PTR [ebp - 4]  // x
      add eax, DWORD PTR [ebp - 8]  // y
      mov DWORD PTR gg, eax  // gg
      push DWORD PTR gg  // gg
      push DWORD PTR [ebp - 8]  // y
      push DWORD PTR [ebp - 4]  // x
      call f
      add esp, 12
      mov  esp, ebp   // MM  deallocate x and y
   }
}

int main() {
   printf("%d\n", g(5, 10));
}
