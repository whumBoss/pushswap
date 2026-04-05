/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:47:51 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 22:16:38 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

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

void	find_biggest_node(t_stack **satck_b)
{
	int	biggest_index;
	int	position;

	if (!*satck_b || !(*satck_b)->next)
		return ;
	biggest_index = count_nodes(*satck_b) - 1;
	position = find_node_position(*satck_b, biggest_index);
	if (position <= biggest_index / 2)
	{
		while ((*satck_b)->index != biggest_index)
			mv_rotate(satck_b, "rb");
	}
	else if (position >= biggest_index / 2)
	{
		while ((*satck_b)->index != biggest_index)
			mv_reverse_rotate(satck_b, "rrb");
	}
}

int	chunk_size(int stack_size)
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

void	algo_over_five(t_stack **satck_a, t_stack **satck_b, int stack_size)
{
	int	i;
	int	chunksize;

	i = 0;
	chunksize = chunk_size(stack_size);
	while (*satck_a)
	{
		if ((*satck_a)->index <= i)
		{
			mv_push(satck_a, satck_b, "pb");
			i++;
		}
		else if (*satck_a && (*satck_a)->index <= i + chunksize)
		{
			mv_push(satck_a, satck_b, "pb");
			mv_rotate(satck_b, "rb");
			i++;
		}
		if (*satck_a && (*satck_a)->next)
			mv_rotate(satck_a, "ra");
	}
	while (*satck_b)
	{
		find_biggest_node(satck_b);
		mv_push(satck_b, satck_a, "pb");
	}
}
