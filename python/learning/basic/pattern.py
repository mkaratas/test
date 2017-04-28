#!/usr/bin/python
#! -*- coding: UTF-8 -*-

import re

content = "6、不要拿我对你的容忍，当做你不要脸的资本。"
c = "9、你是杀马特，我是非主流，道不同不相为谋，分手！"

print content
#subContent = re.sub(r'\s*\d+\s?、', "", c)
subContent = re.sub(r'\d+?、', "", c)
print subContent

