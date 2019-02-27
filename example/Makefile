LIBS = $(shell pkg-config --libs glu freeglut)

PROGRAMS = rect 
PROGRAMS += reshape1 reshape2 reshape3
PROGRAMS += single double
PROGRAMS += primitives concave colorcube

.SUFFIXES: .c .cpp .h

.c.o:
	gcc -o $*.o -c $<

.cpp.o:
	g++ -o $*.o -c $<

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS)
	rm -f *.o

rect: rect.o
	gcc rect.o -o $@ $(LIBS)

reshape1: reshape1.o
	gcc reshape1.o -o $@ $(LIBS)

reshape2: reshape2.o
	gcc reshape2.o -o $@ $(LIBS)

reshape3: reshape3.o
	gcc reshape3.o -o $@ $(LIBS)

single: single.o
	gcc single.o -o $@ $(LIBS)

double: double.o
	gcc double.o -o $@ $(LIBS)

primitives: primitives.o
	gcc primitives.o -o $@ $(LIBS)

concave: concave.o
	gcc concave.o -o $@ $(LIBS)

colorcube: colorcube.o
	g++ colorcube.o -o $@ $(LIBS)


