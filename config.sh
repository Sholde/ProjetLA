#!/bin/bash

if [ $# != 0 ]
	then exit 1
fi

# pwd renvoie le répertoire courant
# ## pour pouvoir écrire des chose après
# test si les répertoires existe et les créer sinon

if [ -d ${pwd##/bin} ]
	then echo "Dossier déjà existant"
	else mkdir bin
fi

if [ -d ${pwd##/obj} ]
	then echo "Dossier déjà existant"
	else mkdir obj
fi

exit 0
