path=/home/user/lib/SFML-2.5.1
name=sfml-app
DEPS=Reservoir.hh Vanne.hh Moteur.hh Module.hh System.hh Pompe.hh
OBJ=Pompe.o Module.o Main.o
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
