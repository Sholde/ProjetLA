#!/bin/bash

if [ $# != 2 ]
	then 
		echo "Need 2 arguments !"
		exit 1
fi

if [ -e path.txt ]
	then
		rm path.txt
		touch path.txt
		echo $1 >> path.txt
		echo $2 >> path.txt
	else
		touch path.txt
		echo "Création du fichier path.txt"
		echo $1 >> path.txt
		echo $2 >> path.txt
fi

make config

# pwd renvoie le répertoire courant
# ## pour pouvoir écrire des chose après
# test si les répertoires existe et les créer sinon

if [ -d ${pwd##/bin} ]
	then echo "Dossier bin déjà existant"
	else mkdir bin
fi

if [ -d ${pwd##/obj} ]
	then echo "Dossier obj déjà existant"
	else mkdir obj
fi

exit 0
