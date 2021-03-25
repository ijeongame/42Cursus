#!/bin/bash

#/bin/bash -C /set_autoindex.sh
bash set_autoindex.sh

service nginx start
service mysql start
service php7.3-fpm start

# nginx -g "daemon off;"
