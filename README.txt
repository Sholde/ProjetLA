########
## INFO
########

On utilise 2 librairie externes.

########
## LIBRAIRIE GRAPHIQUE
########

On utilise SFML version 2.5.1.

########
## INSTALLATION
########

1er cas: (débrouiller vous)
sudo apt-get install libsfml-dev

2eme cas: (le cas qu'on a choisis)
https://www.sfml-dev.org/download/sfml/2.5.1/
Installer la lib et spécifier le chemin dans le makefile.


########
## LIBRAIRIE JSON
########

On utilise la librairies de nlohmann.

########
## INSTALLATION
########

git clone https://github.com/nlohmann/json.git

Et ensuite il faut specifier dans le makefile la ou vous l'avez installez.

########
## COMPILATION
########

make

########
## EXECUTION
########

make run
