#include <iostream>

using namespace std;

class base 
{
public:
	virtual void test(int a) {};
private:
	int a;
};

int main()
{
	base obj;
	
	return 0;
}
