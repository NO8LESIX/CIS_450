#include <iostream>
using namespace std;

class A
{
public:
	int i;
	short s;

	A() {}
	A(int i, short s) { this->i = i; this->s = s; }
};

void main()
{
	A *ap1 = new A();
	A *ap2 = new A(1, 3);
	A a1;
	A a2(2, 6);
	//char dummy;

	//cout << "ap1->i = " << ap1->i << ",  ap1->s = " << ap1->s << "\n";
	//cout << "ap2->i = " << ap2->i << ",  ap2->s = " << ap2->s << "\n";
	//cout << "a1.i = " << a1.i << ",  a1.s = " << a1.s << "\n";
	//cout << "a2.i = " << a2.i << ",  a2.s = " << a2.s << "\n";
	//cin >> dummy;
}