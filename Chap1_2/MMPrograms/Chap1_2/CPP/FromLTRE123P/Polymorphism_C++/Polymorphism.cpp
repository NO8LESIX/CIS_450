#include <iostream>

using namespace std;

class A {
public:
	int a;
	//void f(int i);
};

class B :public A {
public:
	int b;
	//void g(int j);
};

//void A::f(int i)
//{
//	a = i;
//}
//
//void B::g(int j)
//{
//	b = j;
//}

int main() 
{
	int x = 100;
	A a;

	cout << "x = " << x << "\n";

	B *bp = (B *)&a;

	bp->a = 10;
	bp->b = 20;

	cout << "x = " << x << "\n";

	return 0;
}