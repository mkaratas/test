#include <stdio.h>
#include <jni.h>
#include <jni_md.h>

int main(int argc, char **argv)
{
	JNIEnv *env = NULL;
	JavaVM *jvm;
	JavaVMInitArgs vm_args;
	JavaVMOption options[3];
	char ClassPath[1024] = {0};
	sprintf(ClassPath, "-Djava.class.path=.");

	options[0].optionString = "-Djava.compiler=NONE";
	options[1].optionString = ClassPath;
	options[2].optionString = "-verbose:jni";

	jclass cls;
	jmethodID mid;
	
	long status;

	vm_args.version = JNI_VERSION_1_6;
	vm_args.nOptions = 1;
	vm_args.options = options;
	vm_args.ignoreUnrecognized = JNI_FALSE;

	status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
	if (status != JNI_ERR) {
		cls = env->FindClass("Hello");
		if (cls == NULL) 
			printf("cls is null\n");
		else
			printf("cls has value\n");
		mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");	
		if (!mid) {
			printf("method is null\n");
		} else {
			printf("have found main function\n");
			env->CallStaticVoidMethod(cls, mid, NULL);
		}
	} else {

	}
	
	jvm->DestroyJavaVM();
	return 0;
}
