#include <iostream>

using namespace std;

class animal {
public:
	animal(){}
	~animal() {}
	virtual void show(void) {cout << "animal show" << endl;}
private:
	
};

class dog : public animal {
public:
	dog() {}
	~dog() {}
	void show(void) {cout << "dog show" << endl;}
	
};

int main(int argc, char **argv)
{
	animal *ani = new animal();
	ani->show();
	
	dog *d = new dog();
	d->show();

	animal *ani_dog = new dog();
	ani_dog->show();

	delete(d);
	delete(ani);
	delete(ani_dog);

	return 0;
}
