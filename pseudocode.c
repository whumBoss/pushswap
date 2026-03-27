/*	PSEUDOCODE

PUSHSWAP

ALGO AMIR&ALEXSUD

	PARSING

tu recois une liste de nb neg ou positive entre le int min et le int max
tu les trie si c'est deja le cas tu fait rien
si il y a des doublons tu sors erreur
gestion de signes: si t'as un signe neg ou positif il faut que le char d'avt soit un ' ' et char d'apres soit un nb
quand tu trie tu sors les mouv que t'as fait
en plus pour la correc
tu dois pouvoir gerer les nb en input qd ils sont sep par des espaces et quand ils sont entre "" et sep par des esp
43 2 5 "6 57 0"


Creer 2 struct de liste chainé la a et la b, 
tout mettre a NULL,
remplir la a, en verifiant si les inputs sont correct,
Puis parcourir la liste pour verif les doublons
puis parcourir la liste pour assigner les index, la valeur la plus petite est remplace par 0, la 2e plus petite valeur est remplace par 1;
On a pas besoin de concerver les valeurs, on les numerote de 0 a ... dans leurs ordre de base 
puis on vas les trier

	EXEC

coder tout les mouvements

Un algo pour liste de 2
un algo pour liste de 3
un algo pour liste de 5
un algo pour tout ce qui est strictemt sup a 5

*/