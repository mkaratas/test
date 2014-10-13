#include <iostream>

using namespace std;

class A {
public:
	virtual void print() { cout << "This is A" << endl;}
};

class B : public A {
public:
	void print() { cout << "This is B" << endl;}
};

int main(int argc, char **argv)
{
	A a;
	B b;
	A *pa = &a;
	A *pb = &b;

	a.print();
	b.print();

	pa->print();
	pb->print();

	return 0;
}
