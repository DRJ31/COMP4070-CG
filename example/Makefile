LIBS = $(shell pkg-config --libs glu freeglut)
LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"
FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL 
RM = rm -f
CXX = g++
CFLAGS = -Wall
PROGRAMS = rect 
PROGRAMS += reshape1 reshape2 reshape3
PROGRAMS += single double
PROGRAMS += primitives concave colorcube

ifeq ($(shell uname), Darwin)
	LIBS = $(LIBPATH) $(FRAMEWORK)
endif

.cpp.o:
	$(CXX) -o $@ -c $< $(CFLAGS)

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)
	$(RM) *.o

$(PROGRAMS): %: %.o
	$(CXX) $< -o $@ $(LIBS) $(CFLAGS)
