int f() {
_asm {
   // allocate 8 bytes for local variables
   sub esp, 8

   // the body uses ebx
   mov ebx, DWORD PTR [ebp+8]
   mov eax, ebx
   mov ecx, ebx
   mov edx, ecx
   mov esi, edx
   mov edi, esi

   // deallocate local variables
   mov esp, ebp
 }
}