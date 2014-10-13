#include <iostream>

using namespace std;

class Base {
public:
	Base();
	virtual ~Base();
};

class Derived : public Base {
public:
	Derived();
	~Derived();
};

Base::Base()
{
	std::cout << "Base constructor\n";
}

Base::~Base()
{
	std::cout << "Base destructor\n";
}

Derived::Derived()
{
	std::cout << "Derived constructor\n";
}

Derived::~Derived()
{
	std::cout << "Derived destructor\n";
}

int main(int argc, char **argv)
{
	Base *b = new Derived();
	delete(b);

	return 0;
}
