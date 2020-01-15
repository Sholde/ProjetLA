CXX = g++

SFML = ~/lib/SFML-2.5.1
JSON = ~/lib/json

EXEC = app.exe

DEPS = $(wildcard src/*.hh)
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:*.cpp=*.o)

option = -lsfml-graphics -lsfml-window -lsfml-system

FLAG = -Wall -g3

all: compil

compil: $(OBJ)
	@ echo -n édition des liens...
	@ cd bin/
	@ $(CXX) $(OBJ) -o ${EXEC} -L${SFML}/lib ${option}
	@ cd ..
	@ echo OK

%.o: %.cpp ${DEPS}
	@ echo -n compilation de $@... 
	@ $(CXX) -c -o bin/$@ src/$< -I${SFML}/include -I${JSON}/include $(FLAG)
	@ echo OK

run:
	@ export LD_LIBRARY_PATH=${SFML}/lib && echo starting... && ./bin/${EXEC} && echo ending...
	

clear:
	@ echo -n suppréssion des fichiers objets...
	@ rm bin/*.o
	@ echo OK
	
zip: clear
	@ rm *.tar.gz
	@ tar -czvf BOUTON_Nicolas-DEDARALLY_Taariq.tar.gz *
