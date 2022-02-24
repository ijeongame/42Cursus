#!/bin/bash

# 이 shell파일은 컨테이너가 올라갈때마다 실행이 되는데,
# if문 안의 내용들은 처음에만 실행되면 되기 때문에 if문 걸어줌.
if [ ! -e /var/www/html/index.php ]; then
  # wordpress setting
  cp -R /wordpress/* /var/www/html/
  rm /var/www/html/wp-config-sample.php
  cp wp-config.php /var/www/html/wp-config.php
  chown -R www-data:www-data /var/www/html

  # wordpress 설치
  wp core download --locale=ko_KR --allow-root
  until wp core install --url=$DOMAIN_NAME --title=HelloWP --admin_user=$WP_USER1_ID --admin_password=$WP_USER1_PASSWORD --admin_email=hkwon@student.42seoul.com --allow-root --skip-email --path='/var/www/html/'; do
  sleep 0.5
  done
  # wordpress user 생성
  wp user create --allow-root $WP_USER2_ID ijeong@student.42seoul.fr --user_pass=$WP_USER2_PASSWORD --role=author
fi

service php7.3-fpm stop
# wordpress를 foreground로 돌리기
php-fpm7.3 --nodaemonize
