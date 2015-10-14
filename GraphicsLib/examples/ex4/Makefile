TARGET = test.exe

CXX	  = c:\usr\local\mingw64\bin\g++.exe
FILES = main.cpp Graphics.cpp
OBJS = $(FILES:.cpp=.o)

GINCS   = -I/usr/local/include
GLIBS   = -L/usr/local/lib -lfreeglut -lglu32 -lopengl32 -Wl,--subsystem,windows

all:  $(TARGET)

$(TARGET):  $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(GLIBS)

%.o:    %.cpp
	$(CXX) -c $< -o $@ $(GINCS)

clean:
	del $(TARGET) $(OBJS)
