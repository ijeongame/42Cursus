FROM	debian:buster

ENV		AUTOINDEX on

ARG		WP_NAME=wordpress
ARG		WP_USER=hkwon
ARG		WP_PWD=hkwon

LABEL	maintainer="hkwon@student.42seoul.kr"

RUN		apt-get -y update; apt-get -y upgrade

RUN		apt-get -y install nginx openssl php-fpm mariadb-server php-mysql php-mbstring vim curl

COPY	./srcs/* ./

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
		-subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=hkwon/CN=localhost" \
		-keyout localhost.dev.key -out localhost.dev.crt; \
		mv localhost.dev.crt etc/ssl/certs/; \
		mv localhost.dev.key etc/ssl/private/; \
		chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key; \
		cp /default /etc/nginx/sites-available/default

RUN		curl -O https://wordpress.org/latest.tar.gz; \
		tar -xzf latest.tar.gz -C var/www/html/; \
		chown -R www-data:www-data /var/www/html/wordpress; \
		cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php; \
		sed -i "s/database_name_here/${WP_NAME}/g" /var/www/html/wordpress/wp-config.php; \
		sed -i "s/username_here/${WP_USER}/g" /var/www/html/wordpress/wp-config.php; \
		sed -i "s/password_here/${WP_PWD}/g" /var/www/html/wordpress/wp-config.php

RUN		curl -O https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz; \
		tar -xzf phpMyAdmin-5.0.4-all-languages.tar.gz -C var/www/html; \
		mv var/www/html/phpMyAdmin-5.0.4-all-languages var/www/html/phpmyadmin; \
		cp /config.inc.php var/www/html/phpmyadmin/

RUN		service mysql start; \
		mysql -e "CREATE DATABASE ${WP_NAME}; \
		USE ${WP_NAME}; \
		CREATE USER '${WP_USER}'@'localhost' IDENTIFIED BY '${WP_PWD}'; \
		GRANT ALL PRIVILEGES ON wordpress.* TO '${WP_USER}'@'localhost' WITH GRANT OPTION; \
		FLUSH PRIVILEGES;"

RUN 	chown -R www-data:www-data /var/www/html/

EXPOSE	80 443

ENTRYPOINT ["/bin/bash", "-C", "/run.sh"]
