path=/home/user/lib/SFML-2.5.1
name=sfml-app
DEPS=Class.hh Interface.hh Pompe.hh Constants.hh 
OBJ=Interface.o Pompe.o Main.o
option=-lsfml-graphics -lsfml-window -lsfml-system
hidden=@


all: compil clear

compil: $(OBJ) lien
	${hidden} g++ $(OBJ) -o ${name} -L${path}/lib ${option}
	${hidden} echo édition des liens... OK

%.o: %.cpp ${DEPS}
	${hidden} g++ -c $< -I${path}/include

lien:
	${hidden} echo création des liens... OK

run:
	${hidden} export LD_LIBRARY_PATH=${path}/lib && echo starting... && ./${name} && echo ending...
	

clear:
	${hidden} rm *.o
	${hidden} echo suppréssion des fichiers objets... OK
