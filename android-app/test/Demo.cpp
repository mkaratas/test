#include <iostream>

using namespace std;

class Test {
private:
	int mVal;

public:
	void setVal(int var) {
		mVal = var;
	}

	int getVal(void) {
		return mVal;
	}
};

int main(int argc, char **argv) {
	cout << "hello";
	Test *t = new Test();
	t->setVal(10222);
	cout << t->getVal();

	return 0;
}

