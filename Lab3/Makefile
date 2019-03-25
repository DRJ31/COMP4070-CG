CXX = g++
CFLAGS = -Wall
LIBS = $(shell pkg-config --libs glu freeglut)
LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"
FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL 
BIN = ./bin
SRCPATH = ./src
TARGETS = fly robot
PROGRAMS = $(patsubst %,$(BIN)/%,$(TARGETS))
RM = rm -f
CP = cp -f

$(shell test -d $(BIN) || mkdir -p $(BIN))
$(shell test -d $(OBJ) || mkdir -p $(OBJ))
$(shell test -e $(BIN)/Makefile || $(CP) Makefile.bin $(BIN)/Makefile)

ifeq ($(shell uname), Darwin)
	LIBS = $(LIBPATH) $(FRAMEWORK)
	CFLAGS = -w
endif

.PHONY: clean $(TARGETS)

all: $(PROGRAMS)

$(TARGETS): %: $(BIN)/%

$(BIN)/fly: $(SRCPATH)/fly.cpp
	$(CXX) -o $@ $< $(CFLAGS) $(LIBS)

clean:
	$(RM) $(PROGRAMS)
	$(RM) $(OBJ)/*.o
