#!/usr/bin/env python 
import os

class Student(object):
	def __init__(self, name, score):
		self.name = name
		self.__score = score

	def print_score(std):
		print '%s: %s' % (std.name, std.score)

	def get_grade(self):
		if self.score >= 90:
			return 'A'
		elif self.score >= 60:
			return 'B'
		else:
			return 'C'

	def get_name(self):
		return self.__name
		
	def get_score(self):
		return slef.__score

bart = Student('cjz', 90)
lisa = Student('Lisa', 33)

print 'bart name = %s' % (bart.name)

print 'os name: %s' % (os.name)
