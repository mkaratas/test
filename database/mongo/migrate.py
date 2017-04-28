#!/usr/bin/env python
import pymongo

mongo_remote = pymongo.MongoClient('mongodb://192.168.0.119:27018').adserver
mongo_huawei_cloud = pymongo.MongoClient('mongodb://117.78.40.106:27017').adserver

mongo_local = pymongo.MongoClient('mongodb://60.205.113.127:20000').adserver

device = mongo_huawei_cloud.comments.find({});

mongo_local.comments.insert_many(device);
#num = 0;
#for d in device:
#    num+=1
#    print "count = %d"%num
