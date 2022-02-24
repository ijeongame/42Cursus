FROM debian:buster

RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install nginx openssl

COPY ./tools/default ./

RUN openssl req -newkey rsa:2048 -days 365 -nodes -x509 \
    -subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=hkwon/CN=localhost" \
    -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt;

RUN cp ./default    /etc/nginx/sites-enabled/default

EXPOSE 443

ENTRYPOINT [ "nginx" ]
CMD [ "-g", "daemon off;" ]


# CMD ["/bin/sh"]
