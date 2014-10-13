#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char **argv)
{
	string name("cjz");
	string str("hello");
	vector<string> v(5, "cjz");
	vector< vector<string> > vv;
	v[2] = "swust" + str;
	for (vector<string>::size_type i = 0; i != v.size(); i++)
		cout << v[i] << endl;

	vector<string> v1(5);
	cout << v1.size() << endl;
	for (vector<string>::size_type i = 0; i != v1.size(); i++) {
		if (v1[i].empty()) {
			cout << "value = null" << endl;
			//cout << v1[i] << endl;
		}
	}
	
	cout << v[7] << endl;

	return 0;
}
