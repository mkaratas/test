#include <iostream>

using std::cout;
using std::endl;

template <typename T>
T min(T a, T b)
{
	return (a>b) ? b : a;
}

int main(int , char **)
{
	int n1 = 10, n2 = 20;
	double c1 = 8.2, c2 = 2.3;

	cout << "min int   : " << min(n1, n2) << endl;
	cout << "min double: " << min(c1, c2) << endl;

	return 0;
}
