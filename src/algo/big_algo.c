/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:47:51 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 20:12:48 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
	la stackA a ete videe et la stackB a ete remplie
	maintenant je dois remplir la stackA dans le bon ordre
	
	je vais push un par un les nodes de la b dans la a 
	mais avant de push elle vas chercher le node que je souhaite push dans la stackB
	
	pour ca j'ai une fonction qui:
	compte le nb de node dans b 
	cherche la position du plus grd node contenue dans b dans cette meme stack
	puis monte ce node en tete de list pour pouvoir le push facilement
	
	donc si le node est dans la premier moitier je vais rotate tout les nodes
	qui sont avant lui jusqu'a ce qu'il soit le premier
	et si le node est dans la 2e moitier je vais reverse rotate tout les nodes
	qui sont apres lui et lui aussi pour le ramene en tete de list
*/

int	find_node_position(t_stack *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

void	find_biggest_node(t_stack **stackB)
{
	int	biggest_index;
	int	position;

	if (!*stackB || !(*stackB)->next)
		return ;
	biggest_index = count_nodes(*stackB) - 1;
	// printf("\nnb nodes dans b = %d\n", biggest_index);
	position = find_node_position(*stackB, biggest_index);
	// printf("node's position in b = %d\n", position);
	if (position <= biggest_index / 2)
	{
		while ((*stackB)->index != biggest_index)
			mv_rotate(stackB, "rb");
	}
	else if (position >= biggest_index / 2)
	{
		while ((*stackB)->index != biggest_index)
			mv_reverse_rotate(stackB, "rrb");
	}
}

int	chunk_size(int	stack_size)
{
	int	chunksize;
	
	if (stack_size <= 100)
		chunksize = stack_size / 8;
	if (stack_size <= 250)
		chunksize = stack_size / 10;
	else
		chunksize = stack_size / 15;
	return (chunksize);
}

void	algo_over_five(t_stack **stackA, t_stack **stackB, int stack_size)
{
	int	i;
	int	chunksize;
	
	i = 0;
	chunksize = chunk_size(stack_size);
	while (*stackA)
	{
		if ((*stackA)->index <= i)
		{
			mv_push(stackA, stackB, "pb");
			i++;
		}
		else if (*stackA && (*stackA)->index <= i + chunksize)
		{
			mv_push(stackA, stackB, "pb");
			mv_rotate(stackB, "rb");
			i++;
		}
		if (*stackA &&(*stackA)->next)
			mv_rotate(stackA, "ra");
	}
	while (*stackB)
	{
		find_biggest_node(stackB);
		mv_push(stackB, stackA, "pb");
	}
}