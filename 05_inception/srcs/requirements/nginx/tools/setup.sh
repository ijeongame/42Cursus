#!bin/bash

if [ ! -f /etc/ssl/certs/inception_server.crt ] ; then
    openssl req -newkey rsa:2048 -days 365 -nodes -x509 \
        -subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=hkwon/CN=localhost" \
        -keyout /etc/ssl/private/inception_server_pkey.key -out /etc/ssl/certs/inception_server.crt;
fi

nginx -g "daemon off;"
