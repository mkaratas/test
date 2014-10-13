#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	int i(1024);
	int a();
	int *p = new int;
	int *pp = new int();
	cout << *p << endl;
	cout << *pp << endl;
	cout << i << endl;
	string num = "0";
	vector<string> vs(10, "cjz");
	vector<string>::iterator iter;
	for (iter = vs.begin(); iter != vs.end(); iter++) {
		//*iter = "cjzswust";
		cout << *iter << endl;
	}

	delete(p);
	p = NULL;
	delete(p);
	//cout << *(iter+9) << endl;

	return 0;
}
