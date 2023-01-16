# Makefile wrapper to bring up SQL container 

REPO_NAME=bitnami/postgresql
TAG=latest
IMAGE_NAME=$(REPO_NAME):$(TAG)
#TAG=15

# Container options
DB_PORT=5432
PG_PASSWORD=brian_butterfield
PG_USER=postgres

# Mountpoints 
DB_DIR_HOST=container
# This is the dir required for persistence (https://github.com/bitnami/containers/tree/main/bitnami/postgresql#readme)
DB_DIR_DOCKER=/bitnami/postgresql

# More notes on non-root container permissions 
# # https://docs.bitnami.com/tutorials/running-non-root-containers-on-openshift
# TODO: may need to move to docker-compose 

pull:
	docker pull $(REPO_NAME):$(TAG)

run:
	docker run -it \
		-p $(DB_PORT):$(DB_PORT) \
		-e POSTGRES_PASSWORD=$(PG_PASSWORD) \
		-v $(DB_DIR_HOST):$(DB_DIR_DOCKER) \
		-w $(DB_DIR_DOCKER) \
		$(IMAGE_NAME) \
		bash

stop:
	docker stop $(IMAGE_NAME)

sql:
	docker exec -it \
		-p $(DB_PORT):$(DB_PORT) \
		-e POSTGRES_PASSWORD=$(PG_PASSWORD) \
		-v $(DB_DIR_HOST):$(DB_DIR_DOCKER) \
		-w $(DB_DIR_DOCKER) \
		$(IMAGE_NAME) \
		psql -U $(PG_USER)


print-%:
	@echo $* = $($*)
