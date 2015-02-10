#include <stdio.h>
#include <jni.h>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_displayHelloWorld (JNIEnv *env, jobject jobj) {
	printf("Helloworld!\n");
	return;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
	printf("JNI onload function\n");
}
