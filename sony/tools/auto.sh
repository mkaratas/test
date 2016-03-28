#/bin/bash

if [ -z "$1" ]
then
	echo "Usage: "
	echo "	$0 project_name"
	echo 
	echo "	This script is used to automatically generate a C based project" 
	echo
	exit
fi

echo "#include <stdio.h>" >> $1.c
echo >> $1.c
echo "int main(int argc, char** argv)" >> $1.c
echo "{" >> $1.c
echo >> $1.c
echo "	return 0;" >> $1.c
echo "}" >> $1.c
	

#Makefile
echo "srctree=\$(CURDIR)" >> Makefile
echo >> Makefile
echo "CC=gcc
CXX=g++
CFLAGS= -O2 -Wall" >> Makefile
echo >> Makefile
echo "all: $1" >> Makefile
echo "$1: $1.c" >> Makefile
echo "	\$(CC) \$(CFLAGS) -o \$@ \$^" >> Makefile 
echo >> Makefile
echo "PHONY:clean" >> Makefile
echo "clean:" >> Makefile
echo "	rm -rf $1 .*.swp" >> Makefile

vim $1.c
