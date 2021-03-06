# variable

CXX = g++

SFML = /home/user/lib/SFML-2.5.1
JSON = /home/user/lib/json

EXEC = app.exe
ARCHIVE = BOUTON_Nicolas-DEDARALLY_Taariq
TAR = tar.gz

SRCDIR = src
OBJDIR = obj
BINDIR = bin

DEPS = $(wildcard $(SRCDIR)/*.hh)
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

SFML_OPTION = -lsfml-graphics -lsfml-window -lsfml-system

FLAG = -Wall -g3

# make

all: compil

compil: $(OBJ)
	@ $(CXX) -o $(BINDIR)/$(EXEC) $(OBJ) -L$(SFML)/lib $(SFML_OPTION)
	@ echo "Linking complete!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	@ $(CXX) -c -o $@ $< -I$(SFML)/include -I$(JSON)/include $(FLAG)
	@ echo "Compiled "$@" successfully!"

run:
	@ export LD_LIBRARY_PATH=$(SFML)/lib && echo starting... && ./$(BINDIR)/$(EXEC) && echo ending...
	

clean:
	@ if [ $(ARCHIVE).$(TAR) ]; then rm -f $(ARCHIVE).$(TAR); echo "Archive removed!"; fi
	@ rm -f $(OBJDIR)/*
	@ echo "Object files removed!"
	@ rm -f $(BINDIR)/*
	@ echo "Executable removed!"
	
package: clean
	@ tar -czvf $(ARCHIVE).$(TAR) *
	@ echo "Archive created!"
