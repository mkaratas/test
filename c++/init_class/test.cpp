#include <iostream>
using namespace std;
class A {
public:
	A() {cout << "A constructor\n";}
	~A() {}

	
};

class B {
public:
	B() {cout << "B constructor\n";}
	~B() {}

private:
	A a;
};

int main(int argc, char **argv)
{
	B b;

	return 0;
}

