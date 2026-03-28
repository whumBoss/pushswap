/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:35:03 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/28 15:46:26 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
/*
la fonction check args
la fonction printError juste write la sortie d'erreur
*/
void	printError(char *str)
{
	ft_printf("Pushswap error : %s\n", str);
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
			return (1);
		if (fillStackA(av, &stackA))
			return (1);
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
		free_stack(&stackA);
		free_stack(&stackB);
		return (0);
	}
	printError("expected 2 arg");
	return (1);
}