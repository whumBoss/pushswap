/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:19 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/28 20:28:07 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

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
*/

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
		testFillStack(*stackA);
	}
	return(0);
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
		// printf("\n\n--- NOUVELLE ITERATION ---\n\n");
		// printf("buffer = %d\n", buffer);
		while (copystack->next != NULL)
		{
			copystack = copystack->next;
			// printf("copystack->value = %d\n", copystack->value);
			if (buffer == copystack->value)
				return (1);
		}
		copystack = stackA;
		while (buffer != copystack->value)
			copystack = copystack->next;
		copystack = copystack->next;
		buffer = copystack->value;
		// printf("\ncopystack->value at the end = %d\n", copystack->value);
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
	j = 0;
	while (av[i])
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			return (printError("arg allocation gone wrong (split)"), 1);
		while (arg[j])
		{
			if (pushback(arg[j], stackA))
				return (free_stack(stackA), 1);
			j++;
		}
		j = 0;
		free_tab(arg);
		i++;
	}
	testFillStack(*stackA);
	if (verif_doublon(*stackA))
		return (printError("args are identical values"), 1);
	//printf("size = %d\n", size_list(*stackA));
	assign_index(stackA, size_list(*stackA));
	return (0);
}
