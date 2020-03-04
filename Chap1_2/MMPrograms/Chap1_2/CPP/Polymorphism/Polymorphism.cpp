#include <iostream>
using namespace std;

class X
{
  public:
	int x;
	X() { x = 5; }
	void xx()
	{
		x = x + 10;
	}
};
class A: public X
{
  public:
    int a;
    A() {a = 1;}
    virtual void f() 
    {
       a = a + 10;
    }
   
    virtual void g()
    {
       a = a - 10;
    }
};


class B: public A
{
  public:
   int b;
   B() {b = 10;}
   void f() 
   {
      a = a + 100;
      b = b + 200;
   }

   void h()
   {
     a = 0;
     b = 0;
   } 
};

class C: public A
{
  public:
   int c;
   C() {c = 100;}
   void g()
   {
      a = a - 100;
      c = c - 200;
   }
};

int main()
{
   A *ap1 = new A();
   A *bp1 = new B();
   A *bp2 = new B();
   A *cp1 = new C();

   ap1->f();
   ap1->g();
   ap1->xx();

   bp1->f();
   bp2->g();
   ((B *)bp1)->h();
   bp2->xx();

   cp1->f();
   cp1->g();
   cp1->xx();
}

