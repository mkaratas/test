#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os
import docker

class Jenkins:
    def  __init__(self):
        print("Welcome to Jenkins docker!\n")

    def downloadImage(self):
        os.system("docker pull jenkins")

    def createContainer(self):
        os.system("docker run -dti --name jenkins -p 28080:8080 -p 50000:50000 -v /home/chaoming/fred:/mnt/ jenkins")

    def getAdminPwd(self):
        print("Admin passwd: ")
        os.system("docker logs `docker ps -a | grep jenkins | awk '{print $1}'` | egrep '^[0-9a-z]{32}'")

if __name__ == "__main__":
    dockerClient = docker.Client(base_url='unix://var/run/docker.sock',version='1.12',timeout=10)
#    images = dockerClient.images()
#    print(images['RepoTags'])
    #dockerClient.images.list()
    dockerClient.images().get("jenkins:latest")
    #jenkins = Jenkins()
    #jenkins.downloadImage()
    #jenkins.createContainer()
    #jenkins.getAdminPwd()

