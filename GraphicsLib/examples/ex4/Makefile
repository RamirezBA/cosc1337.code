# Makefile for COSC1337 Graphics Library

TARGET 	= test
FILES 	= main.cpp Graphics.cpp
OBJS	= $(FILES:.cpp=.o)

CFLAGS	= -I/usr/local/include

# system specific flags
ifeq ($(OS),Windows_NT)
	OSTYPE = WIN
	LDFLAGS = -lglut32 -lglu32 -lopengl32 -Wl,--subsystem,windows
	EXEFILE = $(TARGET)exe
	CXX = c:\usr\local\mingw32\bin\g++.exe

else
    UNAME_S := $(shell uname -s)
	EXEFILE = $(TARGET)
	CXX = g++
    ifeq ($(UNAME_S), Linux)
		OSTYPE = LINUX
		LDFLAGS = -lGL -lGLU -lglut
    endif
    ifeq ($(UNAME_S), Darwin)
		OSTYPE = MAC
		CFLAGS = -Wno-deprecated-declarations
		LDFLAGS = -framework OpenGL -framework GLUT
    endif
endif

$(EXEFILE):	$(OBJS)
	$(CXX) -o $(EXEFILE) $(OBJS) $(LDFLAGS)
	
%.o:	%.cpp
	g++ -c $< -o $@ $(CFLAGS)

.PHONY:
clean:
	$(RM) $(OBJS) $(EXEFILE)
