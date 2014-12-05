#include <iostream>

using namespace std;

class pizza {
public:
	void product() {cout << "pizza" << endl;}
	static void show() {cout << "show" << endl;}
};

int main(int argc, char **argv)
{
	pizza p;
	p.product();

	pizza *pa = new pizza;
	pa->product();
	pizza *ppa = new pizza();
	ppa->product();

	pizza::show();
	delete(pa);
	delete(ppa);

	return 0;
}
