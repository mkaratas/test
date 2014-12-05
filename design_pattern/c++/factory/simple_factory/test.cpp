#include <iostream>

using namespace std;

enum CTYPE {
	COREA,
	COREB,
};

class SingleCore {
public:
	virtual void Show() = 0;
};

class SingleCoreA : public SingleCore {
public:
	void Show() {cout << "Single Core A" << endl;}
};

class SingleCoreB : public SingleCore {
public: 
	void Show() {cout << "Single Core B" << endl;}
};

class Factory {
public:
	SingleCore* CreateSingleCore(enum CTYPE ctype) {
		switch (ctype) {
			case COREA:
				return new SingleCoreA();
			case COREB:
				return new SingleCoreB();
			default:
				cout << "no such core" << endl;
				break;
		}
	}
};


