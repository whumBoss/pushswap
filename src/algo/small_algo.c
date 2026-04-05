/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:24:11 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 22:14:00 by wihumeau         ###   ########.fr       */
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

void	which_algo(t_stack **satck_a, t_stack **satck_b)
{
	int	stack_size;

	stack_size = count_nodes(*satck_a);
	if (stack_size == 2)
		algo_two_nodes(satck_a);
	if (stack_size == 3)
		algo_three_nodes(satck_a);
	if (stack_size <= 5)
		algo_four_five_nodes(satck_a, satck_b);
	if (stack_size > 5)
		algo_over_five(satck_a, satck_b, stack_size);
	(void)satck_b;
}

void	algo_two_nodes(t_stack **satck_a)
{
	mv_rotate(satck_a, "ra");
}

void	algo_three_nodes(t_stack **satck_a)
{
	if ((*satck_a)->index == 0 && (*satck_a)->next->index == 1)
		return ;
	if (((*satck_a)->index == 1 && (*satck_a)->next->index == 2)
		|| (*satck_a)->index == 0)
		mv_reverse_rotate(satck_a, "rra");
	if ((*satck_a)->index == 2)
		mv_rotate(satck_a, "ra");
	if ((*satck_a)->index == 1 && (*satck_a)->next->index == 0)
		mv_swap(satck_a, "sa");
}

void	algo_four_five_nodes(t_stack **satck_a, t_stack **satck_b)
{
	int	rep;

	rep = 0;
	while (rep < 5)
	{
		if ((*satck_a)->index == 3)
		{
			mv_push(satck_a, satck_b, "pb");
			rep = 5;
		}
		mv_rotate(satck_a, "ra");
		rep++;
	}
	rep = 0;
	while (rep < 5)
	{
		if ((*satck_a)->index == 4)
		{
			mv_push(satck_a, satck_b, "pb");
			mv_rotate(satck_b, "rb");
			rep = 5;
		}
		else
			mv_rotate(satck_a, "ra");
		rep++;
	}
	algo_three_nodes(satck_a);
	while (*satck_b)
	{
		mv_push(satck_b, satck_a, "pa");
		mv_rotate(satck_a, "ra");
	}
}
