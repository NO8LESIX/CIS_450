#include <stdio.h>

void main() {
  register int i, j, k, l;

  i = 34;
  j = i + 2;
  k = j + 3;
  l = k + 4;

  printf("%d\t%d\t%d\t%d\n", i, j, k, l);
}

