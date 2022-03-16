FROM debian:buster

RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install nginx openssl

COPY ./tools/ ./

RUN cp ./default /etc/nginx/sites-available/default

EXPOSE 443

ENTRYPOINT [ "/bin/bash" ]

CMD [ "setup.sh" ]
