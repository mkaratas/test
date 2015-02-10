CROSS_COMPILE ?=
CXX=$(CROSS_COMPILE)g++
C_INCLUDE=-I/usr/lib/jvm/java-6-oracle/include
C_LIB=-L/usr/lib/jvm/java-6-oracle/lib -L/usr/lib/jvm/java-6-oracle/jre/lib/amd64/server -L/usr/lib/jvm/java-6-oracle/jre/lib/amd64


all:hello

hello:hello.cpp
	$(CXX) $(C_INCLUDE) $(C_LIB)  -o $@ $< -ljvm

.PHONY:clean
clean:
	rm -rf hello
