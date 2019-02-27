LIBS = $(shell pkg-config --libs glu freeglut)

PROGRAMS = rect 
PROGRAMS += reshape1 reshape2 reshape3
PROGRAMS += single double
PROGRAMS += primitives concave colorcube

.SUFFIXES: .cpp .h

.cpp.o:
	g++ -o $*.o -c $<

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS)
	rm -f *.o

rect: rect.o
	g++ rect.o -o $@ $(LIBS)

reshape1: reshape1.o
	g++ reshape1.o -o $@ $(LIBS)

reshape2: reshape2.o
	g++ reshape2.o -o $@ $(LIBS)

reshape3: reshape3.o
	g++ reshape3.o -o $@ $(LIBS)

single: single.o
	g++ single.o -o $@ $(LIBS)

double: double.o
	g++ double.o -o $@ $(LIBS)

primitives: primitives.o
	g++ primitives.o -o $@ $(LIBS)

concave: concave.o
	g++ concave.o -o $@ $(LIBS)

colorcube: colorcube.o
	g++ colorcube.o -o $@ $(LIBS)


