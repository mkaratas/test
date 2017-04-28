#!/usr/bin/python
# -*- coding: UTF-8 -*-

import requests
import json

gUserList = [
        {"username": "18911249557", "passwd": "123"},
        {"username": "13716131986", "passwd": "123"},
        {"username": "13810062369", "passwd": "123"},
        {"username": "15010341663", "passwd": "123"},
        {"username": "15011295712", "passwd": "123"},
        {"username": "15726682922", "passwd": "123"},
        {"username": "18910315032", "passwd": "123"},
        {"username": "18501211702", "passwd": "123"},
        {"username": "18901261260", "passwd": "123"},
        {"username": "18901166992", "passwd": "123"},
        {"username": "13311161813", "passwd": "123456"},
        {"username": "15810067612", "passwd": "123456"},
        {"username": "17319214336", "passwd": "123456"},
        {"username": "17710137499", "passwd": "123456"},
        {"username": "18510511311", "passwd": "123456"}
]

class Cafeteria:
    host = "http://life.ctyun.com.cn"
    loginPath = "/admin/ajax/userLogin"
    getMealPath = "/ajax/getTodayMeal"
    reservePath = "/ajax/takeOrder"
    headers = {'content-type': 'application/json'}
    userList = []
    meal = ""
    total = 0
    succeeded = 0
    failed = 0

    def __init__(self, ul):
        self.userList = ul

    def getLoginPath(self):
        return self.loginPath

    def startSession(self):
        self.session = requests.Session()

    def endSession(self):
        self.session.close()

    def getUserList(self):
        return self.userList

    def userLogin(self, user, passwd):
        res = self.session.post(self.host + self.loginPath, 
                data=json.dumps({"userPhone": user, "userPassword": passwd}), 
                headers=self.headers)
        userJson = json.loads(res.text)
        if userJson['returnObj']['isLogin'] == 0:
            print(u"用户: %s 登陆失败."%user)
            print(u"\033[31m%s\033[0m"%userJson['returnObj']['errorMessage'])
            return 0
        else:
            result = userJson['returnObj']['userRealname']
            print(u"用户: %s 登陆成功."%result)
            return 1 

    def getTodayMeal(self):
        #if self.meal != "":
        #    return self.meal

        res = self.session.post(self.host + self.getMealPath, 
                data=json.dumps({"pageSize":6,"pageNo":1,"query":{}}), 
                headers=self.headers)
        meals = json.loads(res.text)
        result = meals['returnObj']['result']
        if len(result) == 0: 
            print(u"\033[31m不是订餐时间\033[0m\n")
            return 0
        else: 
            for i in result:
                #print("meal %s: %s"%(i['remainingNum'],i['mealName']))
                if (i['mealName'] == u"只限西山赢府"):
                    self.meal = i['id']
                    remain = i['remainingNum']
                    print(u"%s - 还剩份数: %d 份"%(i['mealName'], remain))
                    if remain == 0:
                        print(u"\033[33m已被订完\033[0m\n")
                        return 0
                    else:
                        return result[0]['id']

    def reserve(self, meal):
        print u"开始订餐"
        res = self.session.post(self.host + self.reservePath, 
                data=json.dumps({"addressId":2, "id": meal}), 
                headers=self.headers)
        result = json.loads(res.text)
        if result['returnObj']['isSuccess'] == 1:
            print(u"\033[32m订餐成功: %s.\033[0m"%result['returnObj']['msg'])
            self.succeeded += 1
            return 1
        else:
            print(u"\033[31m订餐失败: %s.\033[0m"%result['returnObj']['msg'])
            self.failed += 1
            return 0

    def getSucceeded(self):
        return self.succeeded

    def getFailed(self):
        return self.failed

if __name__ == "__main__":
    print "\n=========欢迎使用全自动订餐程序============"
    print " Authon: Fred"
    print " Email: cjzswust@gmail.com"
    print "===========================================\n"

    cafeteria = Cafeteria(gUserList)
    for user in cafeteria.getUserList():
        cafeteria.startSession()
        res = cafeteria.userLogin(user['username'], user['passwd'])
        if res == 0:
            cafeteria.endSession()
            print("\n")
            continue
        meal = cafeteria.getTodayMeal()
        if meal != 0:
            cafeteria.reserve(meal)
        else:
            cafeteria.endSession()
            break
        cafeteria.endSession()
        print("\n")

    print("============== 订餐结果 ===================")
    print(u"人数: %d 人"%len(gUserList))
    print(u"成功: %d 份"%cafeteria.getSucceeded())
    print(u"失败: %d 份"%cafeteria.getFailed())
    print("===========================================\n")
