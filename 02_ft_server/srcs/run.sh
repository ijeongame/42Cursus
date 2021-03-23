#!/bin/bash

/bin/bash -C /setup_autoindex.sh $1

service nginx start
service php7.3-fpm start
nginx -g  "daemon off;"