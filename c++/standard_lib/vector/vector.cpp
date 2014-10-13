#include <iostream>
#include <vector>

using std::vector;
//using namespace std;

struct Test {
	int a;
	std::string name;
};

int main(int argc, char **argv)
{
	Test t = {10, "cjz"};
	vector<std::string> v;
	v.push_back("cjz");
	v.push_back("swust");
	
	vector<std::string> v1(v);
	vector<Test> vt;
	vt.push_back(t);
	vector<Test> vt1(vt);

	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;

	std::cout << v1[0] << std::endl;
	std::cout << v1[1] << std::endl;

	std::cout << vt[0].a << ", " << vt[0].name << std::endl;
	std::cout << vt1[0].a << ", " << vt1[0].name << std::endl;

	vector<int> i(1);
	
	return 0;
}
