int g() {
_asm {
   // allocate 8 bytes for local variables
     sub esp, 8

   // the body does not use ebx
   mov eax, DWORD PTR[ebp+8]

   // deallocate local variables
   mov esp, ebp
  }
}