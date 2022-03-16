FROM debian:buster

RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install mariadb-server

COPY ./tools/* ./
RUN   cp ./50-server.cnf    /etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE 3306

ENTRYPOINT [ "/bin/bash" ]

CMD [ "setup.sh" ]
