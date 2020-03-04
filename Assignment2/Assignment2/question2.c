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
		} else {
			j -= i;
		}
	 } 
	 x = i;
     y = j; */

    _asm {

	}
	printf("x = %d\ty = %d\n", x, y);
}