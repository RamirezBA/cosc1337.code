# Makefile for Complex number class

APP_TARGET	= demo
TEST_TARGET	= run_tests

# directories -----------------------------------
SRC_DIR		= src
TEST_DIR	= tests
INC_DIR		= include

# file lists ------------------------------------
FILES 	= $(wildcard $(SRC_DIR)/*.cpp)
OBJS 	= $(FILES:.cpp=.o)
TESTS 	= $(wildcard $(TEST_DIR)/*.cpp)
TOBJS 	= $(TESTS:.cpp=.o)
COBJS	= $(filter-out $(SRC_DIR)/main.o, $(OBJS))

# build flags -----------------------------------
CFLAGS 	= -I $(INC_DIR)
LFLAGS	=

# tools -----------------------------------------
CXX 	= g++
RM		= rm -f

# build targets ---------------------------------
all:	$(APP_TARGET) $(TEST_TARGET)

$(APP_TARGET):	$(OBJS)
	$(CXX) -o $@ $(LFLAGS) $^

$(TEST_TARGET):	$(TOBJS)
	$(CXX) -o $@ $(LFLAGS) $^ $(COBJS)

clean:
	$(RM) $(APP_TARGET) $(TEST_TARGET) 
	$(RM) $(OBJS) $(TOBJS)

make.deps:	$(FILES) $(TESTS)
	$(CXX) -MM $(CFLAGS) $^ > make.deps

# implicit rules --------------------------------

%.o:	%.cpp make.deps
	$(CXX) -c $(CFLAGS) $< -o $@

