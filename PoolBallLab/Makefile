# Makefile for building Graphics demo on command line
FILES 	= $(wildcard *.cpp)
OBJS	= $(FILES:.cpp=.o)
TARGET 	= demo

ifeq ($(OS), Windows_NT)
	EXT = .exe
	RM	= del
	CFLAGS =
	LDFLAGS = -glut32 -lglu32 -lopengl32 -Wl,--subsystem,windows
	CXX = c:\usr\local\mingw32\bin\g++.exe
else
	EXT =
	RM 	= rm -f
	CXX = g++
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
	    CFLAGS = -I/usr/include
		LFLAGS = -lGL -lGLU -lglut
	endif
	ifeq ($(UNAME_S), Darwin)
		CFLAGS = -I/usr/local/include
		CFLAGS += -Wno-deprecated-declarations
		LFLAGS = -framework OpenGL -framework GLUT
	endif
endif

all:	demo$(EXT)

$(TARGET)$(EXT):	$(OBJS)
	g++ -o $(TARGET)$(EXT) $(OBJS) $(LFLAGS)

%.o:	%.cpp
	g++ -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(TARGET)$(EXT) $(OBJS)

