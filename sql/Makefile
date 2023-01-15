# Makefile wrapper to bring up SQL container 

REPO_NAME=bitnami/postgresql
TAG=latest
#TAG=15

# Mountpoints 
DB_DIR_HOST=
DB_DIR_DOCKER=


pull:
	docker pull $(REPO_NAME):$(TAG)

run:
	docker run -it \
		-v $(DB_DIR_HOST):$(DB_DIR_DOCKER) \
		-w $(DB_DIR_DOCKER) \
		$(REPO_NAME):$(TAG) \
		bash
