#include <iostream>
#include "Factory.h"

using namespace std;

Factory::Factory ()
{
	cout << "Factory constructor" << endl;
}

Factory::~Factory()
{
	cout << "Factory destructor" << endl;
}

ConcreteFactory::ConcreteFactory()
{
	cout << "ConcreteFactory constructor" << endl;
}

ConcreteFactory::~ConcreteFactory()
{
	cout << "ConcreteFactory destructor" << endl;
}

Product *ConcreteFactory::CreateProduct()
{
	
}
