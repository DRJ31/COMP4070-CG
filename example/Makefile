LIBS = $(shell pkg-config --libs glu freeglut)
LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"
FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL 
RM = rm -f
CXX = g++
CFLAGS = -Wall
BIN = ./bin
OBJ = ./obj
SRCPATH = ./src
PROGRAMS = $(patsubst $(SRCPATH)/%.cpp, $(BIN)/%, $(wildcard $(SRCPATH)/*.cpp)) 

$(shell test -d $(BIN) || mkdir -p $(BIN))
$(shell test -d $(OBJ) || mkdir -p $(OBJ))

ifeq ($(shell uname), Darwin)
	LIBS = $(LIBPATH) $(FRAMEWORK)
endif

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)
	$(RM) $(OBJ)/*.o

$(BIN)/%: $(OBJ)/%.o
	$(CXX) $< -o $@ $(LIBS) $(CFLAGS)

$(OBJ)/%.o: $(SRCPATH)/%.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

