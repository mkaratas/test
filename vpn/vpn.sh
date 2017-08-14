#!/bin/bash
apt-get install pptpd

cp .pptpd.conf /etc/pptpd.conf 
cp .pptpd-options /etc/ppp/pptpd-options 
cp .sysctl.conf /etc/sysctl.conf 
cp .rc.local /etc/rc.local 
cp .chap-secrets /etc/ppp/chap-secrets 
/etc/init.d/pptpd restart
