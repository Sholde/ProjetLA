path=/home/user/lib/SFML-2.5.1
name=sfml-app
main=Main
option=-lsfml-graphics -lsfml-window -lsfml-system
hidden=@


all: compil clear

compil: compil.o
	${hidden} g++ ${main}.o -o ${name} -L${path}/lib ${option}
	${hidden} echo édition des liens... OK

compil.o:
	${hidden} g++ -c ${main}.cpp -I${path}/include
	${hidden} echo création des liens... OK

run:
	${hidden} export LD_LIBRARY_PATH=${path}/lib && echo start... && ./${name} && echo end...
	

clear:
	${hidden} rm *.o
	${hidden} echo suppréssion des fichiers objets... OK
