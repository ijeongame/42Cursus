#!/bin/bash

if [ ! -d /var/lib/mysql/$MYSQL_DB_NAME ]; then
  chmod 755 /var/lib/mysql
  chown -R mysql:mysql /var/lib/mysql

  cp ./50-server.cnf    /etc/mysql/mariadb.conf.d/50-server.cnf
  mysql_install_db --user=mysql --datadir=/var/lib/mysql
  service mysql start
  mysql -e "CREATE DATABASE IF NOT EXISTS ${MYSQL_DB_NAME};\
  CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';\
  GRANT ALL PRIVILEGES ON ${MYSQL_DB_NAME}.* TO '${MYSQL_USER}'@'%';\
  ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}'; FLUSH PRIVILEGES;"
  mysqladmin -uroot -p$MYSQL_ROOT_PASSWORD shutdown
fi

exec mysqld_safe
