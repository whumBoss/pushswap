/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:19 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/27 22:34:16 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	replace_value(t_stack **stackA)
{
	
}

	//j'ai besoin de parcourir la liste pour verifier qu'il n'y a pas de doublon
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

int	verif_doublon(t_stack *stackA)
{
	t_stack	*copystack;
	int		buffer;
	
	stackA = stackA->next;
	buffer = stackA->value;
	copystack = stackA;
	while (copystack->next != NULL)
	{
		//printf("\n\n--- NOUVELLE ITERATION ---\n\n");
		//printf("buffer = %d\n", buffer);
		while (copystack->next != NULL)
		{
			copystack = copystack->next;
			//printf("copystack->value = %d\n", copystack->value);
			if (buffer == copystack->value)
				return (1);
		}
		copystack = stackA;
		while (buffer != copystack->value)
			copystack = copystack->next;
		copystack = copystack->next;
		buffer = copystack->value;
		//printf("\ncopystack->value at the end = %d\n", copystack->value);
	}
	return (0);
}

/*
	pushback la liste chainee en boucle avec av[i]
	dans push back je creatnode et je atoi de av[i]
	pour a la fin avoir une liste chainee qui contient des int bases sur les arg recu en input
*/

int	fillStackA(char **av, t_stack **stackA)
{
	int	i;

	i = 0;
	while (av[i])
	{
		pushback(av[i], stackA);
		i++;
	}
	//testFillStack(*stackA);
	if (verif_doublon(*stackA))
		return(1);
	replace_value(stackA);
	return (0);
}

/*free_stack(stackA), */