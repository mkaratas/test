#include <jni.h>
#include <stdio.h>
#include <assert.h>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_displayHelloWorld
  (JNIEnv *env, jobject thiz)
{
	int a = 10 + 20;
	//printf("in c hello world\n");
//	env->javaCallBack();
}


//extern "C" jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
	printf("jni onload vm: %p\n", vm);
	JNIEnv *env = NULL;
	if (vm->GetEnv((void **)&env, JNI_VERSION_1_4) != JNI_OK) {
		printf("%s: vm->GetEnv() Error", __func__);
		return -1;
	}
	assert(env!=NULL);
	printf("env: %p\n", env);
	
	printf("find class\n");
	jclass clazz = env->FindClass("HelloWorld");
	printf("find method\n");
	jmethodID mID = env->GetStaticMethodID(clazz, "displayCallBack", "()V");

	env->CallVoidMethod(clazz, mID);

	return JNI_VERSION_1_4;
}
