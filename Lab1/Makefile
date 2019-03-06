CXX = g++
CFLAGS = -Wall
LIBS = $(shell pkg-config --libs gl freeglut)
LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"
FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL 
BIN = ./bin
SRCPATH = ./src
OBJ = ./obj
SRC = $(filter-out $(SRCPATH)/main.cpp, $(wildcard $(SRCPATH)/*.cpp))
PROGRAMS = $(patsubst $(SRCPATH)/%.cpp, $(BIN)/%, $(SRC))
RM = rm -f

$(shell test -d $(BIN) || mkdir -p $(BIN))
$(shell test -d $(OBJ) || mkdir -p $(OBJ))

ifeq ($(shell uname), Darwin)
	LIBS = $(LIBPATH) $(FRAMEWORK)
endif

all: $(PROGRAMS)

$(PROGRAMS): $(BIN)/%: $(OBJ)/%.o $(OBJ)/main.o
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

$(OBJ)/%.o: $(SRCPATH)/%.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	$(RM) $(BIN)/*
	$(RM) $(OBJ)/*.o
