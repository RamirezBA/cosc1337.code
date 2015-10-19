# Makefile for Poolball demo

#if _Win32
    EXE = .exe
	DEL = del
#else
    EXE =
	DEL = rm -f

FILES   = main.cpp Poolball.cpp Pooltable.cpp
OBJS    = $(FILES:.cpp=.o)
APP     = demo$(EXE)

all:    $(APP)

$(APP): $(OBJS)
	$(CXX) -o $@ $^

%.o:    %.cpp
	$(CXX) -c $< -o $@

clean:
	$(DEL) $(APP) $(OBJS)

