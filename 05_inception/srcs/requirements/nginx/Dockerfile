FROM debian:buster

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install nginx openssl

RUN openssl req -newkey rsa:2048 -days 365 -nodes -x509 \
	-subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=hkwon/CN=localhost" \
	-keyout localhost.dev.key -out localhost.dev.crt; \
	mv localhost.dev.crt etc/ssl/certs/; \
	mv localhost.dev.key etc/ssl/private/; \
	chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key; \
	cp -rp /default /etc/nginx/sites-available/default

EXPOSE 443

ENTRYPOINT ["nginx"]
CMD ["-g", "daemon off;"]
