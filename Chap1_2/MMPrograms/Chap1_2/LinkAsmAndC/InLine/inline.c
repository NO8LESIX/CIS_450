inline save_registers() {
    _asm {
        push eax
        push edx
        push ecx
    }
}

void f(int a) {
    if (a > 0) f(a-1);
	save_registers();
}

