sfml=/home/user/lib/SFML-2.5.1
json=/home/user/lib/json
name=app.exe
DEPS=Constants.hh Class.hh Draw.hh Box.hh BoxCircle.hh Interface.hh Pompe.hh Module.hh System.hh Include.hh Reservoir.hh Moteur.hh Vanne.hh VanneTransi.hh VanneNormal.hh
OBJ=Draw.o Box.o BoxCircle.o Interface.o Pompe.o Module.o System.o Reservoir.o Moteur.o Vanne.o VanneTransi.o VanneNormal.o
option=-lsfml-graphics -lsfml-window -lsfml-system
hidden=@


all: compil

compil: $(OBJ) Utilisateur Main
	${hidden} echo -n édition des liens...  
	${hidden} g++ $(OBJ) Utilisateur.o Main.o -o ${name} -L${sfml}/lib ${option}
	${hidden} echo OK

%.o: %.cpp ${DEPS}
	${hidden} echo -n compilation de $@... 
	${hidden} g++ -c -o $@ $< -I${sfml}/include
	${hidden} echo OK
	
Utilisateur: Utilisateur.cpp Utilisateur.hh ${DEPS}
	${hidden} echo -n compilation de Utilisateur.o... 
	${hidden} g++ -c -o Utilisateur.o $< -I${json}/include
	${hidden} echo OK
	
Main: Main.cpp ${DEPS}
	${hidden} echo -n compilation de Main.o... 
	${hidden} g++ -c -o Main.o $< -I${sfml}/include -I${json}/include
	${hidden} echo OK

run:
	${hidden} export LD_LIBRARY_PATH=${sfml}/lib && echo starting... && ./${name} && echo ending...
	

clear:
	${hidden} rm *.o
	${hidden} echo suppréssion des fichiers objets... OK
