#include <iostream>

using namespace std;

class Base {
protected:
	int prot_mem;
};

class Sneaky : public Base {
	friend void clobber(Sneaky&);
	friend void clobber(Base&);
	void test();
	int j;
};

void clobber(Sneaky &s)
{
	s.j = s.prot_mem = 0;
}

void clobber(Base &b)
{
	//b.prot_mem = 0;
}

void Sneaky::test()
{
	prot_mem = 10;
}

int main(int argc, char **argv)
{
	
	return 0;
}
