# INFO

On utilise 2 librairie externes.

# LIBRAIRIE GRAPHIQUE

On utilise SFML version 2.5.1.

# INSTALLATION

## 1er cas: (débrouiller vous)
<pre>
sudo apt-get install libsfml-dev
</pre>

## 2eme cas: (le cas qu'on a choisis)
<pre>
<a href="https://www.sfml-dev.org/download/sfml/2.5.1/">https://www.sfml-dev.org/download/sfml/2.5.1/<a>
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

<pre>
make
</pre>

# EXECUTION

<pre>
make run
</pre>
