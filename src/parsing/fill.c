/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:19 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/30 18:44:39 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	assign_index(t_stack **stackA)
{
	int		index;
	t_stack	*compare_stackA;
	t_stack	*current_node;

	current_node = *stackA;
	current_node = current_node->next;
	while (current_node)
	{
		index = 0;
		compare_stackA = *stackA;
		while (compare_stackA)
		{
			if (compare_stackA->value < current_node->value)
				index++;
			compare_stackA = compare_stackA->next;
		}
		current_node->index = index;
		current_node = current_node->next;
	}
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
	
	buffer = stackA->value;
	copystack = stackA;
	while (copystack->next != NULL)
	{
		while (copystack->next != NULL)
		{
			copystack = copystack->next;
			if (buffer == copystack->value)
				return (1);
		}
		copystack = stackA;
		while (buffer != copystack->value)
			copystack = copystack->next;
		copystack = copystack->next;
		buffer = copystack->value;
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
	int		i;
	int		j;
	char	**arg;

	i = 0;

	while (av[i])
	{
		j = 0;
		arg = ft_split(av[i], ' ');
		if (!arg)
			return (printError("arg allocation gone wrong (split)"), 1);
		while (arg[j])
		{
			if (pushback(arg[j], stackA))
				return (free_stack(stackA), 1);
			j++;
		}
		free_tab(arg);
		i++;
	}
	*stackA = (*stackA)->next;
	if (verif_doublon(*stackA))
		return (printError("args are identical values"), 1);
	assign_index(stackA);
	return (0);
}
