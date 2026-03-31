/*	PSEUDOCODE

PUSHSWAP

ALGO AMIR&ALEXSKU



	SUJET

pour une liste de 3 elements 3 mouv ou moins
pour une liste de 5 elements 12 mouv ou moins
pour une liste de 100 elements 1500 mouv ou moins
pour une liste de 500 elements 11500 mouv ou moins



PARSING

VERIF

tu recois une liste de nb neg ou positive entre le int min et le int max
tu les trie si c'est deja le cas tu fait rien
si il y a des doublons tu sors erreur
gestion de signes: si t'as un signe neg ou positif il faut que le char d'avt soit un ' ' et char d'apres soit un nb
quand tu trie tu sors les mouv que t'as fait
en plus pour la correc
tu dois pouvoir gerer les nb en input qd ils sont sep par des espaces et quand ils sont entre "" et sep par des esp
43 2 5 "6 57 0"
/!\ NE PAS OUBLIER DE VERIF SI C'EST DEJA DANS LE BON ORDRE /!\


ASSIGNATIONS

Creer 2 struct de liste chainé la a et la b, 
tout mettre a NULL,
remplir la a, en verifiant si les inputs sont correct,
Puis parcourir la liste pour verif les doublons
puis parcourir la liste pour assigner les index, la valeur la plus petite est remplace par 0,
la 2e plus petite valeur est remplace par 1;
On a pas besoin de concerver les valeurs, on les numerote de 0 a ... dans leurs ordre de base 
puis on vas les trier
/!\ RETURN LE NOMBRE DE NOEUDS /!\



MOUVEMENTS

coder tout les mouvements dans chaque mouv fonction il faut ecrire le nom de la fonction,
suivi du nom de la stack concerne soit a ou b:

swap : 
sa -> swap the first 2 nodes in stackA (soit 23 et 12)
sb -> swap the first 2 nodes in stackB (soit 11 et -60)
ss -> swap the first 2 nodes in stackA et stackB (soit sa et sb en mm tmps)

rotate :
ra -> first node is put at the end of the list, 2nd node takes first place 
and all the others node mouve up the chaine too in stackA
rb ->first node is put at the end of the list, 2nd node takes first place 
and all the others node mouve up the chaine too in stackB
rr -> rr and rb at the same time

reverse rotate rr
rra -> last node is put at the begenning of the list,
and all the others node mouve down the chaine too in stackA
rrb -> last node is put at the begenning of the list,
and all the others node mouve down the chaine too in stackB
rrr -> rrr and rrb at the same time

push :
pa -> push first node of stackB in stackA
pb -> push first node of stackA in stackB

ex : 
stackA : 23  12 -4 56
stackB : 11 -60 -8 19

	ALGORITHME

Un algo pour liste de 2
un algo pour liste de 3
un algo pour liste de 5
un algo pour tout ce qui est strictemt sup a 5


Le concept des chunks
chunk = morceaux composee d'un certain nombre de nodes (exemple pour commencer, chunk de 10 nodes)
Grace aux index, je cherche dans ma stackA les nodes dont l'index est entre 0 et 10
Si l'index du node lu est compris entre 0 et la taille du chunk, on l'envoie dans la stackB
Sinon on l'envoie a la fin de la stackA

Pour optimiser le trie je peux:

.Ajouter une condition pour push (soit en debut de list) les nodes aux index inferieur ou egale a 
l'index d'intervalle    <= Premier intervalle des la plus petites valeur mis en haut
La 2e condition pourras push puis rotate (soit en fin de list) les nodes dont les index sont inferieur ou 
egale a l'index d'intervalle + la taille du chunk    <= 2e trie des plus grandes valeur du chunk mis en bas

.Incrementer l'index d'intervalle a chaque node push dans la stackB
Ca permet de faire evoluer les 2 intervalles au fur et a mesure de l'avancement du trie

.Modifier le premier intervalle...
Dans la premiere condition modifier pour push tout les nodes inferieur ou egale pas seulement a líndex d'intervalle
mais a l'index d'intervalle + la moitier de (l'index d'intervalle + la taille du chunk)
De cette maniere les deux intervalles cites precedements font en fait la moitier de la taille totale des nodes regarde


verif_doublon
j'ai besoin de parcourir la liste pour verifier qu'il n'y a pas de doublon
	//donc j'envoie un pointeur de la list pour pouvoir la parcourir sans modifier le contenue
	//je met la value dans un buffer et je passe au prochain noeud
	//chaque fois que je passe au noeud suivant je compare la value avec le buffer
	//si ils sont egales je return 1, printerror, fin du prog
	//si j'ai parcourus toute la liste et que j'ai pas trouver de doublon du buffer
	//je dois recommencer le process avec la value du 2e noeud puis du 3e etc..
	
	//comment faire?
	//j'ai surrement besoin d'une copie de la copie de la list pour pouvoir revenir a la head facilement
	//je peux utiliser le buffer pour revenir au noeud au quel j'en etais 
	//passer au noeud suivant et copier la value

	fillstackA
	pushback la liste chainee en boucle avec av[i]
	dans push back je creatnode et je atoi de av[i]
	pour a la fin avoir une liste chainee qui contient des int bases sur les arg recu en input
*/