LIBS = $(shell pkg-config --libs glu freeglut)
RM = rm -f
CXX = g++
CFLAGS = -Wall
PROGRAMS = rect 
PROGRAMS += reshape1 reshape2 reshape3
PROGRAMS += single double
PROGRAMS += primitives concave colorcube

.cpp.o:
	$(CXX) -o $@ -c $< $(CFLAGS)

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)
	$(RM) *.o

$(PROGRAMS): %: %.o
	$(CXX) $< -o $@ $(LIBS) $(CFLAGS)
