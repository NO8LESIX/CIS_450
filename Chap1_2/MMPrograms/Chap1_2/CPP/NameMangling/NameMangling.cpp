#include <iostream>
using namespace std;

class A
{
  public:
    int i;
    A() { i = 100;}

    void f() {i = i * i;}
    void f(int x) {i = i + x;}
    int f(int x, int y) {i = i - x + y; return i;}
};

int main() 
{
   int m;
   A *ap = new A();   
   ap->f();
   ap->f(5);
   m = ap->f(5, -10);

   return 0;
}
   
