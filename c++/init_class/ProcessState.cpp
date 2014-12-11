#include <iostream>
#include <string>
#include "ProcessState.h"

using namespace std;

namespace android {

static ProcessState *gProcess;

const string ProcessState::descriptor("cjzswust");

ProcessState *ProcessState::self()
{
	ProcessState *gProcess = new ProcessState;
	return gProcess;
}

int open_driver()
{
	return 10;
}

ProcessState::ProcessState() : mDriverFD(open_driver())
{
	cout << "ProcessState constructor" << endl;
}

ProcessState::~ProcessState()
{
	cout << "ProcessState destructor" << endl;
}

}; /* namespace android */
