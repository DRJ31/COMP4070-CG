CXX = g++
CFLAGS = -Wall
LIBS = $(shell pkg-config --libs gl freeglut)
SOURCES = $(filter-out main.cpp, $(wildcard *.cpp))
TARGETS = $(patsubst %.cpp, %, $(SOURCES))
RM = rm -f

all: $(TARGETS)

$(TARGETS): %: %.o main.o
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.cpp.o:
	$(CXX) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	$(RM) $(TARGETS)
	$(RM) *.o