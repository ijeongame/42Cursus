cp ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

service mysql start
mysql -e "CREATE DATABASE ${WP_DB_NAME};"
mysql -e "CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON wordpress.* TO '${MYSQL_USER}'@'%';"
mysql -e "FLUSH PRIVILEGES;"
service mysql stop

exec mysqld_safe
