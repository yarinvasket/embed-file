FLAGS = 
cc = g++
OBJs = 

default : FLAGS += -Ofast
default : all

debug : FLAGS += -g
debug : all

all : bin/parser.out src/main.cpp $(OBJs)
	mkdir -p bin
	$(cc) $(FLAGS) -o bin/main.out src/main.cpp $(OBJs)

bin/parser.out : src/parser.cpp
	mkdir -p bin
	$(cc) $(FLAGS) -o bin/parser.out src/parser.cpp

.PHONY : clean
clean :
	-rm -r bin
