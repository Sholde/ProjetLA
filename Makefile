sfml=/home/user/lib/SFML-2.5.1
json=/home/user/lib/json
name=app.exe
DEPS=Constants.hh Class.hh Draw.hh Box.hh BoxCircle.hh Interface.hh Pompe.hh Module.hh System.hh Include.hh Reservoir.hh Moteur.hh Vanne.hh VanneTransi.hh VanneNormal.hh Utilisateur.hh
OBJ=Draw.o Box.o BoxCircle.o Interface.o Pompe.o Module.o Main.o System.o Reservoir.o Moteur.o Vanne.o VanneTransi.o VanneNormal.o Utilisateur.o
option=-lsfml-graphics -lsfml-window -lsfml-system
hidden=@


all: compil clear

compil: $(OBJ) lien
	${hidden} g++ $(OBJ) -o ${name} -L${sfml}/lib ${option}
	${hidden} echo édition des liens... OK

%.o: %.cpp ${DEPS}
	${hidden} g++ -c -o $@ $< -I${sfml}/include -I${json}/include
	${hidden} echo compilation $@... OK

lien:
	${hidden} echo && echo création des liens... OK

run:
	${hidden} export LD_LIBRARY_PATH=${sfml}/lib && echo starting... && ./${name} && echo ending...
	

clear:
	${hidden} rm *.o
	${hidden} echo suppréssion des fichiers objets... OK
