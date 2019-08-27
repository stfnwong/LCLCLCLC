# LEETCODE GRIND
# BECAUSE I AM EXPECTED TO

# OUTPUT DIRS
BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src
TEST_DIR=test
TEST_BIN_DIR=$(BIN_DIR)/test
PROGRAM_DIR=programs

# Tool options
CXX=g++
OPT=-O0
CXXFLAGS=-Wall -g2 -std=c++14 -D_REENTRANT $(OPT)
TESTFLAGS=-lgtest -lgtest_main
LDFLAGS=
LIBS = 
TEST_LIBS = -lgtest -lgtest_main

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

.PHONY: clean

# Objects
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp  $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

# Objects, but output as assembly
$(ASSEM_OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -S $< -o $(OBJ_DIR)/$@.asm -masm=$(ASM_STYLE)


# Unit tests 
TEST_OBJECTS  := $(TEST_SOURCES:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)
$(TEST_OBJECTS): $(OBJ_DIR)/%.o : $(TEST_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@ 

# ==== TEST TARGETS ==== #
TESTS=test_tree test_tree_traverse
$(TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(OBJ_DIR)/$@.o\
		-o $(TEST_BIN_DIR)/$@ $(LIBS) $(TEST_LIBS)


# ==== PROGRAM TARGETS ==== #
PROGRAMS = tree_traverser lc_tree_traverser
PROGRAM_OBJECTS := $(PROGRAM_SOURCES:$(PROGRAM_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(PROGRAM_OBJECTS): $(OBJ_DIR)/%.o : $(PROGRAM_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

$(PROGRAMS): $(OBJECTS) $(PROGRAM_OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(OBJ_DIR)/$@.o \
		$(INCS) -o $(BIN_DIR)/$@ $(LIBS)

# Main targets 
all : test programs

test : $(OBJECTS) $(TESTS)

programs : $(PROGRAMS)

assem : $(ASSEM_OBJECTS)

clean:
	rm -rfv *.o $(OBJ_DIR)/*.o 

print-%:
	@echo $* = $($*)
