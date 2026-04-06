/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:47:51 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/06 18:10:24 by wihumeau         ###   ########.fr       */
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

void	find_biggest_node(t_stack **stack_b)
{
	int	biggest_index;
	int	position;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	biggest_index = count_nodes(*stack_b) - 1;
	position = find_node_position(*stack_b, biggest_index);
	if (position <= biggest_index / 2)
	{
		while ((*stack_b)->index != biggest_index)
			mv_rotate(stack_b, "rb");
	}
	else if (position >= biggest_index / 2)
	{
		while ((*stack_b)->index != biggest_index)
			mv_reverse_rotate(stack_b, "rrb");
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

void	sort_a_fill_b(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	i;
	int	chunksize;

	i = 0;
	chunksize = chunk_size(stack_size);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			mv_push(stack_a, stack_b, "pb");
			i++;
		}
		else if (*stack_a && (*stack_a)->index <= i + chunksize)
		{
			mv_push(stack_a, stack_b, "pb");
			mv_rotate(stack_b, "rb");
			i++;
		}
		else if (*stack_a && (*stack_a)->next)
			mv_rotate(stack_a, "ra");
	}
}

void	algo_over_five(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	sort_a_fill_b(stack_a, stack_b, stack_size);
	while (*stack_b)
	{
		find_biggest_node(stack_b);
		mv_push(stack_b, stack_a, "pa");
	}
}
