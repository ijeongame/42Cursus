#!/bin/bash

openssl req -newkey rsa:2048 -days 365 -nodes -x509 \
    -subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=hkwon/CN=localhost" \
    -keyout localhost.dev.key -out localhost.dev.crt;

cp ./default        /etc/nginx/sites-available/default

nginx -g "daemon off;"
