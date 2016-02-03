#!/bin/bash

adb root
adb disable-verity
adb shell setenforce 0
adb reboot

