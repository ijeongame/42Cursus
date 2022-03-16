NAME = inception
DOCKER_COMP = docker-compose
YML = ./srcs/docker-compose.yml
UP = up
DOWN = down
DATA_PATH = /home/hkwon/data
DB_DATA = /home/hkwon/data/db
WP_DATA = /home/hkwon/data/wp
# DB_DATA = ./db
# WP_DATA = ./wp
COMPOSE = $(DOCKER_COMP) -p $(NAME) -f $(YML)

all :
	mkdir $(DATA_PATH) $(DB_DATA) $(WP_DATA)
	$(COMPOSE) $(UP) -d --build

down :
	$(COMPOSE) $(DOWN)

up:
	$(COMPOSE) $(UP) -d

fclean :
	$(COMPOSE) $(DOWN) --rmi all --volumes
	rm -rf $(DB_DATA) $(WP_DATA) $(DATA_PATH)

re : fclean all

.PHONY : all down up fclean re
