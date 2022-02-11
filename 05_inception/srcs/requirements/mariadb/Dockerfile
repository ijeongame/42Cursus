FROM debian:buster

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install mariadb-server

COPY ./tools/50-server.cnf ./
COPY ./tools/mariadb ./

EXPOSE 3306

ENTRYPOINT ["/bin/bash"]

CMD ["mariadb.sh"]
