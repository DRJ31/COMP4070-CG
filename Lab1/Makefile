CXX = g++
CFLAGS = -Wall
LIBS = $(shell pkg-config --libs gl freeglut)
LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"
FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL 
SOURCES = $(filter-out main.cpp, $(wildcard *.cpp))
TARGETS = $(patsubst %.cpp, %, $(SOURCES))
RM = rm -f

ifeq ($(shell uname), Darwin)
	LIBS = $(LIBPATH) $(FRAMEWORK)
endif

all: $(TARGETS)

$(TARGETS): %: %.o main.o
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.cpp.o:
	$(CXX) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	$(RM) $(TARGETS)
	$(RM) *.o