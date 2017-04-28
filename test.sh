redisip=117.78.40.106;
mongoip=117.78.40.106;
adserverpath=/mnt/ext-disk1/RemoteJenkinsHome/product/adserver;
echo docker run -d -p 8087:8087 -e LOG=debug -e REDIS=redis://$redisip:6379 -e MONGO=$mongoip:27018/adserver -e PORT=8087 -v $adserverpath/log:/data/adserver/log -v $adserverpath/creative:/data/adserver/creative --link uuloop-mongo:mongo --name product-adserver product/adserver; > com1

echo docker run -d -p 8087:8087 -e LOG=debug -e \
			REDIS=redis://117.78.40.106:6379 \
            -e MONGO=117.78.40.106:27018/adserver \
            -e PORT=8087 \
            -v /mnt/ext-disk1/RemoteJenkinsHome/product/adserver/log:/data/adserver/log \
            -v /mnt/ext-disk1/RemoteJenkinsHome/product/adserver/creative:/data/adserver/creative \
            --link uuloop-mongo:mongo --name product-adserver product/adserver; > com2
