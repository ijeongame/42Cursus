# 어떤 image를 기반으로 시작하는지 정의한다.
FROM	debian:buster

# ARG를 통해 wordpress database의 값을 할당한다.
ARG		WP_NAME=wordpress
ARG		WP_USER=hkwon
ARG		WP_PWD=hkwon

# 생성된 image에 대해 여러가지 정보를 담는다.
LABEL	maintainer="hkwon <hkwon@student.42seoul.kr>"

# 어떤 포트를 사용할 지 알려 container 내부에서 네트워크 포트를 수신 대기 상태로 만든다.
EXPOSE	80 443

# 패키지 관리자 설치
RUN		apt-get -y update; apt-get -y upgrade

# 서버 구축에 필요한 패키지 설치
RUN		apt-get -y install nginx php-fpm mariadb-server php-mysql php-mbstring vim curl

COPY	srcs /

# openssl
RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
		-subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=hkwon/CN=localhost" \
		-keyout localhost.dev.key -out localhost.dev.crt; \
		mv localhost.dev.crt etc/ssl/certs/; \
		mv localhost.dev.key etc/ssl/private/; \
		chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# wordpres
RUN		curl -O https://wordpress.org/latest.tar.gz; \
		tar -xzf latest.tar.gz -C var/www/html/; \
		chown -R www-data:www-data /var/www/html/wordpress; \
		cp -rp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php; \
		sed -i "s/database_name_here/${WP_NAME}/g" /var/www/html/wordpress/wp-config.php; \
		sed -i "s/username_here/${WP_USER}/g" /var/www/html/wordpress/wp-config.php; \
		sed -i "s/password_here/${WP_PWD}/g" /var/www/html/wordpress/wp-config.php

# phpmyadmin
RUN		curl -O https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz; \
		tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz; \
		mv phpMyAdmin-5.0.2-all-languages phpmyadmin; \
		mv phpmyadmin /var/www/html/; \
		cp -rp srcs/config.inc.php var/www/html/phpmyadmin/

# mySQL
RUN		service mysql start; \
		mysql -e "CREATE DATABASE ${WP_NAME}; \
		USE ${WP_NAME}; \
		CREATE USER ${WP_USER}@'localhost' IDENTIFIED BY ${WP_PWD}; \
		GRANT ALL PRIVILEGES ON wordpress.* TO ${WP_USER}@'localhost' WITH GRANT OPTION; \
		FLUSH PRIVILEGES;"

RUN 	chown -R www-data:www-data /var/www/html/

ENTRYPOINT ["/bin/bash", "-C", "/run.sh"]