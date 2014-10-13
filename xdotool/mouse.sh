#/bin/bash

stop_time="18:28"
i=0

while true
do 
	time=`date | awk -F' ' '{print $4}'`
	h=`echo ${time:0:2}`
	echo $h
	sh=`echo ${stop_time:0:2}`
	echo $sh
	if [ $h -ge $sh ]
	then
		break	
	fi

	xdotool mousemove $i 100
	echo "move $i"
	if [ $i -ge 1000 ]
	then
		i=0
	fi	

	i=$[ $i+5 ]
	sleep $[ 60*40 ]
done
