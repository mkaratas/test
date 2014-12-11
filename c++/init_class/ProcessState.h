#ifndef ANDROID_PROCESS_STATE_H
#define ANDROID_PROCESS_STATE_H

namespace android {
using namespace std;

class ProcessState {
public:
	static ProcessState *self();
	const static string descriptor;
	
private:
	int mDriverFD;
	
	ProcessState();
	~ProcessState();
}; 

}; /* namespace android */

#endif /* ANDROID_PROCESS_STATE_H */
