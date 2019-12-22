path=/home/user/lib/SFML-2.5.1
name=sfml-app
DEPS=Constants.hh Class.hh Interface.hh Point.hh Pompe.hh Module.hh System.hh Include.hh Reservoir.hh Moteur.hh Vanne.hh VanneTransi.hh VanneNormal.hh
OBJ=Interface.o Point.o Pompe.o Module.o Main.o System.o Reservoir.o Moteur.o Vanne.o VanneTransi.o VanneNormal.o
option=-lsfml-graphics -lsfml-window -lsfml-system
hidden=@


all: compil clear

compil: $(OBJ) lien
	${hidden} g++ $(OBJ) -o ${name} -L${path}/lib ${option}
	${hidden} echo édition des liens... OK

%.o: %.cpp ${DEPS}
	${hidden} g++ -c -o $@ $< -I${path}/include

lien:
	${hidden} echo création des liens... OK

run:
	${hidden} export LD_LIBRARY_PATH=${path}/lib && echo starting... && ./${name} && echo ending...
	

clear:
	${hidden} rm *.o
	${hidden} echo suppréssion des fichiers objets... OK
