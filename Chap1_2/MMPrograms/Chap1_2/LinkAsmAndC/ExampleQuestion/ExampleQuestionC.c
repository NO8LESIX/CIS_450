#include <stdio.h>

int gi = 10;
unsigned char guc = 20;
short gs = -25;

int f(short ps1, unsigned char puc1, char pc1, int pi1);
int g(int x1, int x2, int x3, int x4);

int main() {
    gi = f(40000, 300, 300, 52);
    printf("gi = %d\tgc=%d\tgs=%d\n", gi, guc, gs);
    return 0;
}

int f(short ps1, unsigned char puc1, char pc1, int pi1) {
    char lc1;
    int li1;
    short ls1;
    unsigned char luc1;
    unsigned short lus1;

    lc1 = ps1 + puc1;
    li1 = pc1 * 2;
    // to "* 2", use shift 1 bit to the left operation
    // i.e., shl eax, 1 
    ls1 = guc - ps1;
    lus1 = gs + gi + 12;
    luc1 = g(lc1, li1, puc1, pi1 + 2);
    gi += (luc1 - li1);
    return gi + ls1 - luc1;
}


int g(int x1, int x2, int x3, int x4) {
    guc = x1 - x3 + gs;
    return gs + x2 - x4;
}
