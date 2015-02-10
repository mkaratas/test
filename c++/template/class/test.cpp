#include <iostream>

template <typename INTERFACE>
class BnInterface {
public:
	const static int descriptor;
	int getInterfaceDescriptor();
};

const BnInterface<INTERFACE>::descriptor(10);

int BnInterface<INTERFACE>::getInterfaceDescriptor()
{
	return descriptor;
}

int main(int, char **)
{
	
}
