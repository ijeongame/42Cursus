FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get -y install php7.3 php-fpm php-cli php-mysql php-mbstring php-xml curl sudo

RUN curl -O https://wordpress.org/latest.tar.gz && \
	tar -xzf latest.tar.gz

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    sudo mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/* ./
EXPOSE 9000

ENTRYPOINT [ "/bin/bash" ]

CMD [ "wordpress.sh" ]
