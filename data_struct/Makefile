# C++ LANGUAGE PREP
# Makefile for some simple programs to practice C++ language and 
# tooling features. 
#
# Stefan Wong 2020

# OUTPUT DIRS
BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src
TEST_DIR=test
ASM_DIR=asm
TEST_BIN_DIR=$(BIN_DIR)/test
#PROGRAM_DIR=programs		# NOTE: no programs yet

# Tool options
CXX=g++
OPT=-O0
CXXFLAGS=-Wall -Wshadow -g2 -std=c++14 -D_REENTRANT $(OPT) 
TESTFLAGS=-lgtest -lgtest_main
LDFLAGS=-pthread
LIBS = 
TEST_LIBS = 

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
TESTS=test_heap test_tree test_binary_tree
$(TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(OBJ_DIR)/$@.o\
		-o $(TEST_BIN_DIR)/$@ $(LIBS) $(TEST_LIBS)


# Main targets 
#
.PHONY: clean

all : test 

test : $(OBJECTS) $(TESTS)

clean:
	rm -rfv *.o $(OBJ_DIR)/*.o 

print-%:
	@echo $* = $($*)
