#include <iostream>
#include "ProcessState.h"

using namespace std;
using namespace android;

int main(int argc, char **argv)
{
	ProcessState::self();

	return 0;
}

