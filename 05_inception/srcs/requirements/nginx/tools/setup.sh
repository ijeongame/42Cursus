#!bin/bash

openssl req -newkey rsa:2048 -days 365 -nodes -x509 \
    -subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=hkwon/CN=localhost" \
    -keyout /etc/ssl/private/inception_server.key -out /etc/ssl/certs/inception_server.crt;

cp ./default    /etc/nginx/sites-available/default

nginx -g "daemon off;"
