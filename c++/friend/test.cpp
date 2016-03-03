#include <iostream>
using namespace std;

void f();

struct X {
	friend void f() {};
	X() { f();}
	void g();
	void h();
};

void X::g() 
{
//	return f();
}


void X::h()
{
	return f();
}

int main(int argc, char **)
{
	return 0;
}
