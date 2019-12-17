path=/home/user/dev/ProjetLA/SFML-2.5.1
name=sfml-app
main=main.cc
option=-lsfml-graphics -lsfml-window -lsfml-system

all: compil

compil: compil.o
	g++ main.o -o ${name} -L${path}/lib ${option}

compil.o:
	g++ -c ${main} -I${path}/include

run:
	export LD_LIBRARY_PATH=${path}/lib && ./${name}
