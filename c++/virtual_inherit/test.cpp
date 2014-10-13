#include <iostream>

using namespace std;

class Base {
public:
	virtual void print();//{ cout <<"Base print\n";}
};

class A : public virtual Base {
public:
	A() {}
	void print(void) override;
	virtual ~A() {}
};

void A::print(void) override;
{
	cout << "A print\n";
}


class B : public virtual Base {
public:
	B() {}
	virtual ~B() {}
};

class C : public B, public A {
public:
	C() {}
	~C() {}
};

int main(int argc, char **argv)
{
	A a;
	B b;
	C c;
	
	c.print();
	return 0;
}
