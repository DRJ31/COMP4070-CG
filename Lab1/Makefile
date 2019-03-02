CXX = g++
CFLAGS = -Wall
LIBS = $(shell pkg-config --libs gl freeglut)
SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCES))
TARGET = lab1
RM = rm -f

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.c.o:
	$(CXX) -o $@ -c $<

.PHONY: clean

clean:
	$(RM) lab1 *.o