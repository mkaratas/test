#!/usr/bin/env python
import os

print 'os name: %s' % (os.name)
#print 'os environ: %s' % (os.environ)
#print 'abs path %s' %(os.path.abspath('.'))

abspath=os.path.abspath('.')
newpath=os.path.join(abspath, 'testdir')
os.mkdir(newpath)
