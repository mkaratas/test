#!/usr/bin/env python
#coding:utf-8

#import xml.dom.minidom
#
#dom=xml.dom.minidom.parse("applist.xml");
#
#app_list = dom.documentElement
#system_apps = app_list.documentElement

SYSTEM_APPS='/system/app'
DALVIK_CACHE_DEX='/data/dalvik-cache'

try:
	import xml.etree.cElementTree as ET
except ImportError:
	import xml.etree.ElementTree as ET
import sys
import os
import time

def getxml(xml):
	try:
		tree=ET.parse(xml)
		apps_list=tree.getroot()
	except Exception, e:
		print "Error: Can not parse file applist.xml." 
		sys.exit(1)
	return apps_list	

'''
function remount is used to remount system partation
'''
def remount():
	os.system("adb root")
	os.system("adb disable-verity")
	os.system("adb shell setenforce 0")
	os.system("adb reboot")
	os.system("adb wait-for-device")
	os.system("adb root")
	#time.sleep(5)
	os.system("adb wait-for-device")
	os.system("adb remount")

def remove():
	os.system("adb wait-for-device")
	os.system("adb root")
	os.system("adb remount")
	root = getxml('applist.xml')
	system_apps=root.find("system/app")
	for item in system_apps:
		print SYSTEM_APPS+"/"+item.text
		os.system("adb shell rm -rf "+SYSTEM_APPS+"/"+item.text)

	dalvikcache_arm_dex=root.find("data/dalvik-cache/arm")
	for item in dalvikcache_arm_dex:
		dex = DALVIK_CACHE_DEX+"/arm/"+item.text
		print dex
		os.system("adb shell rm -rf "+dex)
	dalvikcache_arm64_dex=root.find("data/dalvik-cache/arm64")
	for item in dalvikcache_arm64_dex:
		dex64 = DALVIK_CACHE_DEX+"/arm64/"+item.text
		print dex64
		os.system("adb shell rm -rf "+dex64)
		

def main(argv):
	#remount()
	remove()

if __name__ == '__main__':
	sys.exit(main(sys.argv[1:]))
