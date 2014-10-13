#include <iostream>

using namespace std;

class Interface {
public:
		Interface() {cout << "Interface constructor" << endl;}
		virtual ~Interface();
	void connect(void);

	class Client {
	public:
		Client() {cout << "Client constructor" << endl;}
		~Client() {cout << "Client destructor" << endl;}
	private:
	};

private:
};

void Interface::connect(void)
{
	cout << "Interface connect function" << endl;
	Client *c = new Client();
	
	cout << "Interface connect function end" << endl;
}

Interface::~Interface() 
{
	delete c
	cout << "Interface destructor" << endl;
}

int main(int argc, char **argv)
{
	
	Interface *in = new Interface();
	in->connect();

	return 0;
}
