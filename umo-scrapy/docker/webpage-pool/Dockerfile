FROM python:2.7
MAINTAINER Fred jianzhong.cui@uuloop.com

# os setup
RUN apt-get update
RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app

# install requirements
COPY webpage-pool/requirements.txt /usr/src/app/
RUN pip install --no-cache-dir -r requirements.txt

# move codebase over
COPY webpage-pool /usr/src/app

# override settings via localsettings.py
COPY docker/webpage-pool/settings.py /usr/src/app/localsettings.py

# copy testing script into container
COPY docker/run_docker_tests.sh /usr/src/app/run_docker_tests.sh

# set up environment variables

# run command
CMD ["python", "kafkadump.py", "dump",  "-t", "umo.crawled_firehose", "-p"]