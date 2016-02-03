#!/bin/bash
adb root
adb remount


declare -a app_list=(AndroidPay 
					CrashMonitor
					CrashMonitorSystem
					dropbox
					playstationapp
					com.sonymobile.xperialounge.services
					)

#declare -a dalvik-cache-list=(
#			
#			)


for i in ${app_list[@]}
do
	echo /system/app/$i
	adb shell rm -rf /system/app/$i
done


adb reboot
