/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:24:11 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/06 19:46:13 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	count_nodes(t_stack *stack)
{
	int	stack_size;

	stack_size = 0;
	while (stack)
	{
		stack = stack->next;
		stack_size++;
	}
	return (stack_size);
}

void	which_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = count_nodes(*stack_a);
	if (stack_size == 2)
		algo_two_nodes(stack_a);
	else if (stack_size == 3)
		algo_three_nodes(stack_a);
	else if (stack_size <= 5)
		algo_four_five_nodes(stack_a, stack_b);
	else if (stack_size > 5)
		algo_over_five(stack_a, stack_b, stack_size);
}

void	algo_two_nodes(t_stack **stack_a)
{
	mv_rotate(stack_a, "ra");
}

void	algo_three_nodes(t_stack **stack_a)
{
	if ((*stack_a)->index == 0 && (*stack_a)->next->index == 1)
		return ;
	else if (((*stack_a)->index == 1 && (*stack_a)->next->index == 2)
		|| (*stack_a)->index == 0)
		mv_reverse_rotate(stack_a, "rra");
	if ((*stack_a)->index == 2)
		mv_rotate(stack_a, "ra");
	if ((*stack_a)->index == 1 && (*stack_a)->next->index == 0)
		mv_swap(stack_a, "sa");
}

void	algo_four_five_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int	rep;

	rep = 0;
	while (rep < 5)
	{
		if ((*stack_a)->index == 3)
			mv_push(stack_a, stack_b, "pb");
		else if ((*stack_a)->index == 4)
		{
			mv_push(stack_a, stack_b, "pb");
			mv_rotate(stack_b, "rb");
		}
		else
			mv_rotate(stack_a, "ra");
		rep++;
	}
	algo_three_nodes(stack_a);
	if ((*stack_b)->index == 4)
		mv_rotate(stack_b, "rb");
	while (*stack_b)
	{
		mv_push(stack_b, stack_a, "pa");
		mv_rotate(stack_a, "ra");
	}
}
