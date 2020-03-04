#include <stdio.h>
int gg = 11;

int f(int x, int y, int gg) {
   return x + y + gg;
}

int g(int g1, int g2) {
   int x, y;
   _asm {
      mov  eax, g1
      mov  x, eax
      mov  eax, g2
      mov  y, eax
      mov eax, gg
      add eax, x
      add eax, y
      mov gg, eax
      push gg
      push y
      push x
      call f
      add esp, 12
   }
}

int main() {
   printf("%d\n", g(5, 10));
}
