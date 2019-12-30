sfml=/home/user/lib/SFML-2.5.1
json=/home/user/lib/json
name=app.exe
DEPS=Constants.hh Class.hh Draw.hh Box.hh BoxCircle.hh Interface.hh Pompe.hh Module.hh System.hh Include.hh Reservoir.hh Moteur.hh Vanne.hh VanneTransi.hh VanneNormal.hh
OBJ=Draw.o Box.o BoxCircle.o Interface.o Pompe.o Module.o System.o Reservoir.o Moteur.o Vanne.o VanneTransi.o VanneNormal.o
option=-lsfml-graphics -lsfml-window -lsfml-system
hidden=@


all: compil

compil: $(OBJ) Utilisateur Main lien
	${hidden} g++ $(OBJ) Utilisateur.o Main.o -o ${name} -L${sfml}/lib ${option}
	${hidden} echo édition des liens... OK

%.o: %.cpp ${DEPS}
	${hidden} g++ -c -o $@ $< -I${sfml}/include
	${hidden} echo compilation $@... OK
	
Utilisateur: Utilisateur.cpp Utilisateur.hh ${DEPS}
	${hidden} g++ -c -o Utilisateur.o $< -I${json}/include
	${hidden} echo compilation Utilisateur.o... OK
	
Main: Main.cpp ${DEPS}
	${hidden} g++ -c -o Main.o $< -I${sfml}/include -I${json}/include
	${hidden} echo compilation Main.o... OK

lien:
	${hidden} echo && echo création des liens... OK

run:
	${hidden} export LD_LIBRARY_PATH=${sfml}/lib && echo starting... && ./${name} && echo ending...
	

clear:
	${hidden} rm *.o
	${hidden} echo suppréssion des fichiers objets... OK
