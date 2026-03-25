#include "../includes/pushswap.h"
/*
la fonction check args
la fonction printError juste write la sortie d'erreur
*/
void	printError(void)
{
	write(1, "Error\n", 6);
}

int		main(int ac, char **av)
{
	if (ac > 2)
	{
		t_stack		*stackA;
		t_stack		*stackB;

		stackA = NULL;
		stackB = NULL;
		if (checkInput(av))
			return (printError(), 1);
		// if (fillStackA(ac, stackA))
		// 	return (1);
		/*
		replaceValue(stackA);
		replace value with index
		tu met la valeur du node a comparer dans un buffer
		tu compare le buffer avec la valeur du node suivant en boucle
		quand tu as comparer un node avec toutes les autres valeurs
		tu dois revenir au node qui suit celui que tu viens de comparer
		puis mettre dans le buffer, relancer la boucle pour le comparer avec touts les nodes suivant
		
		algo
		*/
		return (0);
	}
	return (1);
}