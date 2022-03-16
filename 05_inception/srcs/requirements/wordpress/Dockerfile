FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y && \
    apt-get -y install php7.3 php-fpm php-cli php-mysql php-mbstring php-xml wget curl mariadb-client

COPY ./tools/* ./

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN cp www.conf /etc/php/7.3/fpm/pool.d/www.conf && \
    service php7.3-fpm start

EXPOSE 9000

ENTRYPOINT [ "/bin/bash" ]

CMD [ "setup.sh" ]
