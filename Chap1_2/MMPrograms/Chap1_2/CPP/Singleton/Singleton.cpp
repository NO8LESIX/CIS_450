#include <iostream>
using namespace std;

class SingletonClass
{
	int m_value;
	// the following declaration states that class Singleton has 
	// a private class field of type pointer to SingletonClass
	// named theInstance.  
	// However the definition of the variable is done outside class
	// (just as an external static variable in C) - see below
	static SingletonClass *theInstance;

	SingletonClass(int v = 0)
	{
		m_value = v;
	}
public:
	int get_value()
	{
		return m_value;
	}
	void set_value(int v)
	{
		m_value = v;
	}
	static SingletonClass *getInstance()
	{
		if (!theInstance)
			theInstance = new SingletonClass(10);
		return theInstance;
	}

	static int c_value;
};

// Access specifiers will not give you error while defining the member.
SingletonClass *SingletonClass::theInstance;
int SingletonClass::c_value = 128;

// You can also declare regular external/external static variables
int regularExternal = 44;
static int regularExternalStatic;

void main() {
	SingletonClass *singleton1 = SingletonClass::getInstance();
	SingletonClass *singleton2 = SingletonClass::getInstance();

	// You cannot do the following since theInstance is privatre
	// SingletonClass *singleton3 = SingletonClass::theInstance;  

	// the following three statements are ok
	SingletonClass::c_value = 24;
	regularExternal = 22;
	regularExternalStatic = -4;
}
