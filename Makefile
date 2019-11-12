all: compil run

compil: *.cc
	g++ *.cc -o main.exe

run:
	./main.exe
