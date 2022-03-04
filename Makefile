FLAGS = 
cc = g++
OBJs = 
FILEs = 

default : FLAGS += -Ofast
default : all

debug : FLAGS += -g
debug : all

all : arrfiles src/main.cpp $(OBJs)
	mkdir -p bin
	$(cc) $(FLAGS) -o bin/main.out src/main.cpp $(OBJs)

arrfiles : $(FILEs) bin/parser.out
	for file in $(FILES)
	do
		./bin/parser.out $file "$file.arr"
	done

bin/parser.out : src/parser.cpp
	mkdir -p bin
	$(cc) $(FLAGS) -o bin/parser.out src/parser.cpp

.PHONY : clean
clean :
	-rm -r bin
	-rm res/*.arr
