void func1(int p1, int p2, int p3, int p4) {
   int i1, i2, i3, i4;
   i1 = p1;
   _asm { 
       mov  eax, i2
       add  eax, i3
   }
   i4 = i2;
}
