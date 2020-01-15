# Implémentation

On a regroupé Réservoir, Moteur et Vanne dans une super-class Module.
Vanne est la super-class des vannes de transition qui permettent de
mettre a niveau le flux de carburant et des vannes normales qui sont les 
vannes entre les réservoirs et les moteurs.

System regroupe la liste de tous les modules.

Interface est l'interface graphique.

La méthode update() des modules calcul les mises a jour.
La méthode render() des modules affiche les modules.

# Calcul flux de carburant

Pour calculer si le moteur est alimenté, le moteur regarde d'abord le 
réservoir direct, qui lui regarde si il est plein et si il a une pompe 
en fonctionnement qui n'est pas déjà associé a un moteur. 
Si il ne l'alimente pas alors le moteur regarde une
de ses vannes, si la vanne est ouverte alors 
la vanne regarde si le reservoir qui n'est pas le 
réservoir direct (car la vanne a un reservoir commun avec le moteur),
du coup elle regarde si ce reservoir l'alimente. Si il ne l'alimente
pas alors la vanne regarde une de ces voisines car sa voisine sera en
contact avec le reservoir pas encore vu, et du coup ca vérifie le 
réservoir. Et si le moteur est toujour pas alimenté le moteur regarde
son autre vanne direct et fait la même chose que la première vanne.


## exemple moteur m1 :
<pre>
m1 -> tank1

m1 -> v12 -> tank2
			-> v13 -> tank3

m1 -> v13 -> tank3
			-> v12 -> tank2
</pre>

# Calcul des points

Lorsque le pilote vidange un réservoir ou met une pompe en panne il 
gagne 2 points. Si il finit la partie avec un moteur non alimenté il à
0.

# Stokage info des pilotes

On utilise une librairie json.
On a un identifiant qui contient :
		- un mot de passe, 
		- un tableau de date,
		- un tableau de note,
		- un tableau de tableau de string qui stock l'historique
		
Comme on a trois tableau pour savoir à quoi correspond chaque élément 
on regarde l'indice. date[1], rating[1] et history[1] font partie du
même historique.
