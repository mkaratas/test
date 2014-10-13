#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
	bool a = false;
	//bool b = false;
	bool b = true;
	if (!a ^ b) {
		cout << "ture" << endl;
	} else {
		cout << "false" << endl;
	}
	
	return 0;
}
