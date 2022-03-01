#!/bin/bash

cp ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

if [! -d /var/lib/mysql/$WP_DB_NAME]; then
  mysql_install_db --user=mysql --datadir=/var/lib/mysql
  service mysql start
  mysql -e "CREATE DATABASE '${WP_DB_NAME}';"
  mysql -e "CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
  mysql -e "GRANT ALL PRIVILEGES ON '${WP_DB_NAME}'.* TO '${MYSQL_USER}'@'%';"
  mysql -e "FLUSH PRIVILEGES;"
  service mysql stop
fi

exec mysqld_safe
