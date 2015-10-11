FILES = main.cpp
OBJS = $(FILES:.cpp=.o)
TARGET = hello.exe

all: $(TARGET)

$(TARGET):  $(OBJS)
	g++ -o $(TARGET) $(OBJS)

%.o:    %.cpp
	g++ -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS)

