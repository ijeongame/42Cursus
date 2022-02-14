FROM debian:buster

RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install mariadb-server

COPY ./tools/* ./

EXPOSE 3306

ENTRYPOINT [ "/bin/bash" ]

CMD [ "mariadb.sh" ]
