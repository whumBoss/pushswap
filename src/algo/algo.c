/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:24:11 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/02 20:52:24 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	count_nodes(t_stack *stackA)
{
	int	list_size;

	list_size = 0;
	while (stackA)
	{
		stackA = stackA->next;
		list_size++;
	}
	return (list_size);
}

void	which_algo(t_stack **stackA, t_stack **stackB)
{
	int	list_size;

	list_size = count_nodes(*stackA);
	if (list_size == 2)
		algo_two_nodes(stackA);
	if (list_size == 3)
		algo_three_nodes(stackA);
	// if list_size ==4 ?????????? <======== /!\ /!\ /!\.
	if (list_size == 5)
		algo_five_nodes(stackA, stackB);
	// else || if (list_size > 5)
		// algo_over_five();
	(void)stackB;
}

void	algo_two_nodes(t_stack **stackA)
{
	mv_rotate(stackA, "ra");
}

void	algo_three_nodes(t_stack **stackA)
{
	if ((*stackA)->index == 0 && (*stackA)->next->index == 1)
		return ;
	if (((*stackA)->index == 1 && (*stackA)->next->index == 2)
		 || (*stackA)->index == 0)
		mv_reverse_rotate(stackA, "rra");
	if ((*stackA)->index == 2)
		mv_rotate(stackA, "ra");
	if ((*stackA)->index == 1 && (*stackA)->next->index == 0)
		mv_swap(stackA, "sa");
}

void	algo_five_nodes(t_stack **stackA, t_stack **stackB)
{
	int	rep;

	rep = 0;
	while (rep < 5)
	{
		if ((*stackA)->index == 3)
		{
			mv_push(stackA, stackB, "pb");
			rep = 5;
		}
		mv_rotate(stackA, "ra");
		rep++;
	}
	rep = 0;
	while (rep < 5)
	{
		if ((*stackA)->index == 4)
		{
			mv_push(stackA, stackB, "pb");
			mv_rotate(stackB, "rb");
			rep = 5;
		}
		else
			mv_rotate(stackA, "ra");
		rep++;
	}
	algo_three_nodes(stackA);
	while (*stackB)
	{
		mv_push(stackB, stackA, "pa");
		mv_rotate(stackA, "ra");
	}
}

// void	algo_over_five()
// {
// 
// }
