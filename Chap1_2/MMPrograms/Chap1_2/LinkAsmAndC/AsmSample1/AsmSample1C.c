#include <stdio.h>
int gg = 11;

int f(int x, int y, int gg) {
   return x + y + gg;
}

int g(int g1, int g2) {
   int x, y;
   x = g1;
   y = g2;
   gg = gg + x + y;
   return f(x, y, gg);
}

int main() {
   printf("%d\n", g(5, 10));
}
