# Makefile for Complex number class

APP_TARGET	= demo
TEST_TARGET	= run_tests

# directories -----------------------------------
SRC_DIR		= src
TEST_DIR	= tests
INC_DIR		= include

# System dependencies
CFLAGS = -I $(INC_DIR)

ifeq ($(OS), Windows_NT)
	EXT = .exe
	RM = del	
	CFLAGS += -MMD -std=c++11
	CXX = C:\usr\local\mingw32\bin\g++.exe
	PREFIX =
else
	EXT =
	PREFIX = ./
	RM = rm -f
	CXX = g++
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		CFLAGS += -MMD
	endif
	ifeq ($(UNAME_S), Darwin)
		CFLAGS += -MMD
	endif
endif

# file lists ------------------------------------
FILES 	= $(wildcard $(SRC_DIR)/*.cpp)
OBJS 	= $(FILES:.cpp=.o)
TESTS 	= $(wildcard $(TEST_DIR)/*.cpp)
TOBJS 	= $(TESTS:.cpp=.o)
COBJS	= $(filter-out $(SRC_DIR)/main.o, $(OBJS))


# tools -----------------------------------------
CXX 	= g++
RM		= rm -f

# build targets ---------------------------------
all:	$(APP_TARGET)$(EXT) $(TEST_TARGET)$(EXT)

$(APP_TARGET)$(EXT):	$(OBJS)
	$(CXX) -o $@ $(LFLAGS) $^

$(TEST_TARGET)$(EXT):	$(TOBJS)
	$(CXX) -o $@ $(LFLAGS) $^ $(COBJS)

clean:
	$(RM) $(APP_TARGET)$(EXT) $(TEST_TARGET)$(EXT) 
	$(RM) $(OBJS) $(TOBJS)

make.deps:	$(FILES) $(TESTS)
	$(CXX) -MM $(CFLAGS) $^ > make.deps

run:	$(APP_TARGET)$(EXT)
	$(PREFIX)$(APP_TARGET)

test:	$(TEST_TARGET)$(EXT)
	$(PREFIX)$(TEST_TARGET)

# implicit rules --------------------------------

%.o:	%.cpp make.deps
	$(CXX) -c $(CFLAGS) $< -o $@

