#include <iostream>

using namespace std;

class Test {
public:
	void print(void) {
		cout << "in first\n" << endl;
	}
};

class Test {
public:
	void hello(void) {
		cout << "hello\n" <<endl;
	}

};

int main(int argc, char **argv)
{
	Test t;
	t.print();
	t.hello();

	return 0;
}
