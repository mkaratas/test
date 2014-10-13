#!/usr/bin/env python

def test():
	print "test is running"

if __name__ == "__main__":
	print "test main is working"

if __name__ == "test":
	print "test is invoked"

#name=raw_input("please enter your name: ")
#print "hello, ", name

age=20
if age >= 18:
	print 'your age is', age
	print 'adult'
else:
	print 'your age is', age
	print 'teenager'

sum=0
for x in range(101):
	sum = sum + x
print sum
