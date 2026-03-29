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


/*
	REPLACE LA PLUS PETITE VALUE
	
	CHERCHER LA PLUS PETITE VALUE
	acceder au premier noeud
	copier la value du premier noeud dans lowest_value
	continuer de parcourir la liste
	si je rencontre une value qui est plus petite que celle de lowest_value
	remplacer la valeur de lowest_value par cette nvle +petite value
	repeter le processe jusqu'a la fin de la liste
	return lowest_value
	

	
	REPLACE LES AUTRES VALUES
	
	en boucle:

	CHERCHER LA PLUS PETITE VALUE
	j'ai besoin d'une variable index qui sera a 1 au depart
	je recupere lowest_value 
	et je creer next_lowest
	copier la head pour parcourir la liste
	copier la value du premier noeud dans next_lowest
	et copier l'adresse du premier noeud dans un pointeur node
	continuer de parcourir la liste
	si je rencontre une value qui est plus petite que celle de next_lowest et plus grande que lowest_value
	remplacer la valeur de next_lowest par cette nvle +petite value
	remplacer l'adresse contenue dans node par l'adresse de ce node qui contient la plus petite value
	repeter le processe jusqu'a la fin de la liste

	ASSIGNER L'INDEX
	acceder au node pointer par node
	assigner l'index du node a la meme valeur que la variable index creer au depart
	assigner lowest_value a la meme valeur que next_lowest
	incrementer la variable index
	puis recommencer la boucle

int	find_lowest_value(t_stack *stackA)
{
	int	lowest_value;
	
	stackA = stackA->next;
	lowest_value = stackA->value;
	while (stackA->next != NULL)
	{
		stackA = stackA->next;
		if (stackA->value < lowest_value)
			lowest_value = stackA->value;
	}
	return (lowest_value);
}

	//printf("\n\nlowest = %d\n", lowest_value);
	//printf("adress of the copynode = %p\n", node);
	// *stackA = (*stackA)->next;
	// printf("stacknode index = %d\n", (*stackA)->index);
	//printf("adress of original node = %p\n", *stackA);
	// printf("size = %d\n", stack_size);
	// printf("node index = %d\n", node->index);
	// printf("stacknode index = %d\n", (*stackA)->index);

int	assign_index(t_stack **stackA, int stack_size)
{
	int	lowest_value;
	int	next_lowest;
	int	index;
	t_stack	*copy_stackA;
	t_stack	*node;

	index = 1;
	lowest_value = find_lowest_value(*stackA);
	while (index < stack_size)
	{
		copy_stackA = *stackA;
		copy_stackA = copy_stackA->next;
		next_lowest = copy_stackA->value;
		node = copy_stackA;
		printf("\nlowest_value = %d\n", lowest_value);
		printf("next_lowest = %d\n", next_lowest);
		while (copy_stackA->next != NULL)
		{
			copy_stackA = copy_stackA->next;
			if (copy_stackA->value < next_lowest && copy_stackA->value > lowest_value)
			{
				next_lowest = copy_stackA->value;
				node = copy_stackA;
			}
		}
		node->index = index;
		lowest_value = next_lowest;
		index++;
		printf("\nlowest_value = %d\n", lowest_value);
		printf("next_lowest = %d\n", next_lowest);
	}
	return(0);
}
*/