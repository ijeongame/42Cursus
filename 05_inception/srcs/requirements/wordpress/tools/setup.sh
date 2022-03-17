#!/bin/bash

if ! wp core is-installed --allow-root --path='/var/www/html'; then
  wp core download --locale=ko_KR --allow-root --path='/var/www/html'
  wp config create --dbname=$MYSQL_DB_NAME --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --locale=ko_KR --allow-root --path='/var/www/html'
  until wp core install --url=$DOMAIN_NAME --allow-root --title='Hello_WordPress' --admin_user=$WP_USER1_ID\
    --admin_password=$WP_USER1_PASSWORD --admin_email="hkwon@student.42seoul.kr" --path='/var/www/html'; do
  sleep 0.5;
  done

  wp user create --allow-root $WP_USER2_ID ijeong@student.42seoul.kr --user_pass=$WP_USER2_PASSWORD --role=author --path='/var/www/html'
  chown -R www-data:www-data /var/www/html
fi

service php7.3-fpm stop
php-fpm7.3 --nodaemonize
