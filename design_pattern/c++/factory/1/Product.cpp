#include "Product.h"
#include <iostream>

using namespace std;

Product::Product()
{
	cout << "Product constructor" << endl;
}

Product::~Product()
{
	cout << "Product destructor" << endl;
}

ConcreteProduct::ConcreteProduct()
{
	cout << "ConcreteProduct..." << endl;
}

ConcreteProduct::~ConcreteProduct()
{
	cout << "ConcreteProduct destructor" << endl;
}
