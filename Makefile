FLAGS = 
cc = g++
OBJs = 

default : FLAGS += -Ofast
default : all

debug : FLAGS += -g
debug : all

all : src/main.cpp $(OBJs)
	mkdir -p bin
	$(cc) $(FLAGS) -o bin/main.out src/main.cpp $(OBJs)

.PHONY : clean
clean :
	-rm -r bin
