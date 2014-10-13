CXX=g++

#下边这么需要加到环境变量中，在shell中执行
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

JAVA_CLASS += HelloWorld.class

C_SRCS += HelloWorld.cpp
C_SHARED_LIB += libHelloWorld.so
C_FLAGS +=  -shared -fPIC -I/usr/lib/jvm/java-6-oracle/include

all:$(C_SHARED_LIB)
	javac HelloWorld.java

$(C_SHARED_LIB) : $(C_SRCS)
	$(CXX) $(C_FLAGS) -o $@ $<

.PHONY:clean
clean:
	rm -rf $(C_SHARED_LIB) *.class *.log
