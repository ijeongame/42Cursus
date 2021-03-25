#!/bin/bash

if [ "$AUTOINDEX" = "on" ]; then
	echo "autoindex[on]"
	sed -i "s/autoindex off;/autoindex on;/g" /etc/nginx/sites-available/default
else
	echo "autoindex[off]"
	sed -i "s/autoindex on;/autoindex off;/g" /etc/nginx/sites-available/default
fi