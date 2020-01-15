# INFO

On utilise 2 librairie externes.

# LIBRAIRIE GRAPHIQUE

On utilise SFML version 2.5.1.

# INSTALLATION

## 1er cas: (débrouiller vous)
sudo apt-get install libsfml-dev

## 2eme cas: (le cas qu'on a choisis)
<pre>
https://www.sfml-dev.org/download/sfml/2.5.1/
</pre>
Installer la lib et spécifier le chemin dans le makefile + le nom du 
fichier.

# LIBRAIRIE JSON

On utilise la librairies de nlohmann.

# INSTALLATION

<pre>
git clone https://github.com/nlohmann/json.git
</pre>

Et ensuite il faut spécifier dans le makefile le chemin ou vous l'avez 
installez + le nom du fichier.

# COMPILATION

make

# EXECUTION

make run
