FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get -y install php7.3 php-fpm php-cli php-mysql php-mbstring php-xml wget curl

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xvf latest.tar.gz

EXPOSE 9000

ENTRYPOINT [ "/bin/bash" ]

CMD [ "wordpress.sh" ]
