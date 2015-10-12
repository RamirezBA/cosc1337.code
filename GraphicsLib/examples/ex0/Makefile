FILES = main.cpp
OBJS = $(FILES:.cpp=.o)

GINCS   = -I/usr/local/include
GLIBS   = -L/usr/local/lib -lfreeglut -lopengl32

all:  hello.exe

hello.exe:  $(OBJS)
	g++ -o hello.exe $(OBJS) $(GLIBS)

%.o:    %.cpp
	g++ -c $< -o $@ $(GINCS)

clean:
	rm -f hello.exe $(OBJS)
