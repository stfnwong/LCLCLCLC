# LEETCODE GRIND

# OUTPUT DIRS
BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src
TEST_DIR=test
ASM_DIR=asm
TEST_BIN_DIR=$(BIN_DIR)/test
PROGRAM_DIR=programs

# Tool options
CXX=g++
OPT=-O0
CXXFLAGS=-Wall -g2 -std=c++17 -D_REENTRANT $(OPT) -fPIC -shared
TESTFLAGS=
LDFLAGS=-pthread
LIBS= 
TEST_LIBS=

# style for assembly output
ASM_STYLE=intel

# Object targets
INCS=-I$(SRC_DIR)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.hpp)
# Unit tests 
TEST_SOURCES  = $(wildcard $(TEST_DIR)/*.cpp)
# Tools (program entry points)
PROGRAM_SOURCES = $(wildcard $(PROGRAM_DIR)/*.cpp)


# Objects
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp  $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

# Objects, but output as assembly
$(ASSEM_OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -S $< -o $(ASM_DIR)/$@.asm -masm=$(ASM_STYLE)


# Unit tests 
TEST_OBJECTS  := $(TEST_SOURCES:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)
$(TEST_OBJECTS): $(OBJ_DIR)/%.o : $(TEST_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@ 

# ==== TEST TARGETS ==== #
TESTS=test_tree test_threaded_tree test_tree_traverse test_dynamic \
	  test_questions test_vtable

$(TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(OBJ_DIR)/$@.o\
		-o $(TEST_BIN_DIR)/$@ $(LIBS) $(TEST_LIBS)


# ==== PROGRAM TARGETS ==== #
PROGRAMS = tree_traverser obj_tree_traverser
PROGRAM_OBJECTS := $(PROGRAM_SOURCES:$(PROGRAM_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(PROGRAM_OBJECTS): $(OBJ_DIR)/%.o : $(PROGRAM_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

$(PROGRAMS): $(OBJECTS) $(PROGRAM_OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(OBJ_DIR)/$@.o \
		$(INCS) -o $(BIN_DIR)/$@ $(LIBS)

# Main targets 
#
.PHONY: all test programs clean


all : test programs

test : $(OBJECTS) $(TESTS)

programs : $(PROGRAMS)

assem : $(ASSEM_OBJECTS)

clean:
	rm -fv *.o $(OBJ_DIR)/*.o 
	# Clean test programs
	rm -fv $(TEST_BIN_DIR)/test_*

# ==== DOCKER TARGETS ==== #
DOCKER_DEST_DIR=/usr/local/lc
DOCKER_IMAGE_NAME=lc_cpp
DOCKER_CONTAINER_NAME=lclclc
CURRENT_DIR=$(shell pwd)

build-image:
	docker build -t $(DOCKER_IMAGE_NAME) .


run-dev:
	docker run -it \
		-v $(CURRENT_DIR):$(DOCKER_DEST_DIR) \
		-w $(DOCKER_DEST_DIR) \
		$(DOCKER_IMAGE_NAME) \
		bash 

run-test:
	docker run -it \
		-v $(CURRENT_DIR):$(DOCKER_DEST_DIR) \
		-w $(DOCKER_DEST_DIR) \
		$(DOCKER_IMAGE_NAME) \
		make clean && make all && ./test/run_tests.sh

print-%:
	@echo $* = $($*)
