mv /wordpress/* /var/www/html/ && chown -R www-data:www-data /var/www/html && rm -r /wordpress latest.tar.gz
service php7.3-fpm start
service php7.3-fpm stop
