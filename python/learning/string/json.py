#!/usr/bin/python
# -*- coding: UTF-8 -*-

import json

str = "{"handled":false,"statusCode":200,"returnObj":{"pageNo":1,"pageSize":6,"pageCount":1,"rowCount":2,"start":1,"result":[{"id":"2017020913364625257549","idFk":null,"todayDate":null,"status":null,"sum":null,"remainingNum":39,"mealName":"只限西山赢府","createDate":null,"updateDate":null,"path":"/img/default.jpg","addressId":0,"isSuccess":0,"msg":""},{"id":"2017020913374132977242","idFk":null,"todayDate":null,"status":null,"sum":null,"remainingNum":52,"mealName":"只限益园---莲藕猪手饭","createDate":null,"updateDate":null,"path":"/img/default.jpg","addressId":0,"isSuccess":0,"msg":""}],"totalCount":2},"msg":null}"

js = json.loads(str)
print js
