CXX = g++

SFML = ~/lib/SFML-2.5.1
JSON = ~/lib/json

EXEC = app.exe

SRCDIR = src
OBJDIR = obj
BINDIR = bin

DEPS = $(wildcard $(SRCDIR)/*.hh)
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

option = -lsfml-graphics -lsfml-window -lsfml-system

FLAG = -Wall -g3

all: compil

compil: $(OBJ)
	@ $(CXX) -o $(OBJ) $(BINDIR)/$(EXEC) -L$(SFML)/lib $(option)
	@ echo "Linking complete!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	@ $(CXX) -c -o $@ $< -I$(SFML)/include -I$(JSON)/include $(FLAG)
	@ echo "Compiled "$@" successfully!"

run:
	@ export LD_LIBRARY_PATH=$(SFML)/lib && echo starting... && ./$(BINDIR)/$(EXEC) && echo ending...
	

clear:
	@ rm -rf $(BINDIR)/*
	@ rm -rf $(OBJDIR)/*
	@ echo "Executable removed!"
	
zip: clear
	@ tar -czvf BOUTON_Nicolas-DEDARALLY_Taariq.tar.gz *
	@ echo "Archive created!"
