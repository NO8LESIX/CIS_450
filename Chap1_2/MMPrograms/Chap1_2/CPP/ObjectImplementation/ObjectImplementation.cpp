#include <iostream>
using namespace std;

class A
{
  public:
    int i1;
    char c1;
    short s1;
    long l1;

    A() {
      i1 = 3;
      c1 = 4;
      s1 = 5;
      l1 = 6;
    }

    void f(int x) {
      i1 += x;
      c1 += x * 2;
      s1 += x + 3;
      l1 += x - 5;
    }
};

int main()
{
   A *ap1 = new A();
   A *ap2 = new A();
   ap1->f(3);
   ap2->f(5);
   
   return 0;
}
