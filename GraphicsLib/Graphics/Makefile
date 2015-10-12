TARGET = test.exe

FILES = main.cpp Graphics.cpp
OBJS = $(FILES:.cpp=.o)

GINCS   = -I/usr/local/include
GLIBS   = -L/usr/local/lib -lfreeglut -lglu32 -lopengl32 

all:  $(TARGET)

$(TARGET):  $(OBJS)
	g++ -o $(TARGET) $(OBJS) $(GLIBS)

%.o:    %.cpp
	g++ -c $< -o $@ $(GINCS)

clean:
	rm -f $(TARGET) $(OBJS)
