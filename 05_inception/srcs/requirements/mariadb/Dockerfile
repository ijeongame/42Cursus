FROM debian:buster

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install mariadb-server

COPY ./tools/* ./

RUN sed -i 's/bind-address/#bind-address/g' /etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE 3306

ENTRYPOINT ["/bin/bash"]

CMD ["mariadb.sh"]
