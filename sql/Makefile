# Makefile wrapper to bring up SQL container 
SQL_SRC_PATH=db_dir

#REPO_NAME=bitnami/postgresql
REPO_NAME=postgres
TAG=15
IMAGE_NAME=$(REPO_NAME):$(TAG)

# Container options
DB_PORT=5432
PG_PASSWORD=brian
PG_USER=postgres
CONTAINER_NAME=linux_postgres
DB_HOSTNAME=localhost

# NOTE: tihs is a shit name
SQL_FILES_PATH_HOST=$(SQL_SRC_PATH)
SQL_FILES_PATH_DOCKER=/root/$(SQL_SRC_PATH)

# Mountpoints 
DB_DIR_HOST=container
# This is the dir required for persistence (https://github.com/bitnami/containers/tree/main/bitnami/postgresql#readme)
DB_DIR_DOCKER=/var/lib/postgres/data
#DB_DIR_DOCKER=/bitnami/postgresql

# More notes on non-root container permissions 
# # https://docs.bitnami.com/tutorials/running-non-root-containers-on-openshift
# TODO: may need to move to docker-compose 

# Could move to another postgres container, eg
# docker run -d --rm -e POSTGRES_USER=linux -e POSTGRES_PASSWORD=password -p 5432:5432 -v container:/var/lib/postgres/data --name linux_postgres postgres:15


pull:
	docker pull $(REPO_NAME):$(TAG)

run:
	docker run -d --rm \
		--name $(CONTAINER_NAME) \
		-p $(DB_PORT):$(DB_PORT) \
		-e POSTGRES_USER=$(PG_USER) \
		-e POSTGRES_PASSWORD=$(PG_PASSWORD) \
		-v $(DB_DIR_HOST):$(DB_DIR_DOCKER) \
		-v $(SQL_FILES_PATH_HOST):$(SQL_FILES_PATH_DOCKER) \
		$(IMAGE_NAME) 

stop:
	docker stop $(CONTAINER_NAME)

shell:
	docker exec -w $(SQL_FILES_PATH_DOCKER) -it $(CONTAINER_NAME) bash

sql:
	docker exec -it $(CONTAINER_NAME) psql -U $(PG_USER)

sql-local:
	psql -U $(PG_USER) -p $(DB_PORT) -h $(DB_HOSTNAME)

print-%:
	@echo $* = $($*)
