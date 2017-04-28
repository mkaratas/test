# -*- coding: utf-8 -*-
import scrapy


class JokejiSpider(scrapy.Spider):
    name = "jokeji"
    allowed_domains = ["jokeji.cn"]
    start_urls = ['http://jokeji.cn/']

    def parse(self, response):
        pass
