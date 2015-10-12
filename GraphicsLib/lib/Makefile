# Makefile to build Graphics archive on PC

FILES = Graphics.cpp
OBJS = $(FILES:.cpp=.o)
LIB = /c/usr/local/lib
INC = /usr/local/include

TARGET  = libgraphics.a

all:    $(TARGET)

%.o:    %.cpp
	g++ -c $< -o $@ -I$(INC)

$(TARGET):  $(OBJS)
	ar cr $(TARGET) $(OBJS)

install:    $(TARGET)
	cp  $(TARGET) $(LIB)

clean:
	rm -f $(TARGET) $(OBJS)
