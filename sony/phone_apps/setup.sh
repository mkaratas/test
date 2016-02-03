#!/bin/bash

##################### Functions ###############################33
search_device()
{
	echo -e "\033[32mBegin to search device.\033[0m"
	time=0
	while true
	do
		havedevice=`adb devices | grep "device$"`
		if [ -n  "$havedevice" ]
		then
			echo "Device: "$havedevice | awk -F" " '{print $1" " $2}'
			return "1"
		else
			sleep 1
			time=$[time+1]
			echo -e Trying to connect to device "\033[33m$time\033[0m" times."\r\c" # -e 支持转义，\c 表示不换行
			adb kill-server
			if [ $time = 60 ] 
			then
				echo 
				return "0"
			fi
		fi
	done
}

usage()
{
	echo "Usage: $1 [options]"
	echo "	-a	setup all steps"
	echo "	-u	Provide remount envirment"
	echo "	-i	Install my usually used apps."
	echo "	-r	Remove useless apps preinstalled in the phone."
	echo 
}

install()
{
	cd $apps_dir
	for i in `ls`
	do
		adb install $i
	done
}

unlock()
{
	adb root
	adb disable-verity
	adb shell setenforce 0
}

remove()
{
	adb root
	adb remount

	for i in ${app_list[@]}
	do
		echo /system/app/$i
		adb shell rm -rf /system/app/$i
	done
}

########################## Parameter ##########################

top=`pwd`
apps_dir=$top/apps

declare -a app_list=(AndroidPay 
                    CrashMonitor
                    CrashMonitorSystem
					MTKLogger
                    dropbox
                    playstationapp
                    com.sonymobile.xperialounge.services
                    )

########################## Begin #############################

if [ $# == 0 ]; then
	echo $0
	usage $0
	exit
fi

search_device
if [ "$?" = "1" ]
then
	echo "New device found"
else 
	echo "No device found"
	exit
fi

while getopts "auir " arg
do
	case $arg in
		a)
			echo "\033[36mDisable-verity -> setenforce 0 -> remount -> remove rearly used apps -> install my apps\033[0m"
			unlock
			adb reboot;  
			adb kill-server
			search_device
			if [ "$?" = "1" ]; then
				remove
			fi
			search_device
			if [ "$?" = "1" ]; then
				install
			fi
			;;
		u)
			echo -e "\033[36mProvide remount envirment.\033[0m"
			unlock
			adb reboot
			adb kill-server
			;;
		i)
			echo -e "\033[36mInstall my usually used apps.\033[0m"
			install
			;;
		r)
			echo -e "\033[36mRemove useless apps preinstalled in the phone.\033[0m"
			remove
			adb reboot
			adb kill-server
			;;
		?)
			echo "Default"
			;;
	esac
done
