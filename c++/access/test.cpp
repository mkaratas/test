#include <iostream>

using namespace std;

class Test {
public:
	Test();
protected:
private:
	int a;
};

Test::Test()
{
	cout << "Test constructor" << endl;
}

int main(int argc, char **argv)
{
	Test t;	
	t.a = 10;

	return 0;
}
