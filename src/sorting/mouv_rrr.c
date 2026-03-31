/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 21:18:29 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/31 13:19:46 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
/*
rotate :
ra -> first node is put at the end of the list, 2nd node takes first place 
and all the others node mouve up the chaine too in stackA
rb ->first node is put at the end of the list, 2nd node takes first place 
and all the others node mouve up the chaine too in stackB
rr -> rr and rb at the same time


reverse rotate rr
rra -> last node is put at the begenning of the list,
and all the others node mouve down the chaine too in stackA
rrb -> last node is put at the begenning of the list,
and all the others node mouve down the chaine too in stackB
rrr -> rrr and rrb at the same time
*/

void	mv_rotate(t_stack **stack, char *mouv_name)
{
	t_stack	*buffer_last;
	t_stack	*buffer_first;
	buffer_first = (*stack)->next;
	buffer_last = *stack;
	buffer_last->next = NULL;
	*stack = buffer_first;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = buffer_last;
	*stack = buffer_first;
	if (mouv_name[0] != '\0')
		ft_printf("%s\n", mouv_name);
}

void	mv_rr(t_stack **stackA, t_stack **stackB)
{
	mv_rotate(stackA, "\0");
	mv_rotate(stackB, "\0");
	ft_printf("rr\n");
}

void	mv_reverse_rotate(t_stack **stack, char *mouv_name)
{
	t_stack	*buffer_first;
	t_stack	*buffer_last;
	buffer_first = *stack;
	while ((*stack)->next->next != NULL)
		*stack =(*stack)->next;
	buffer_last =(*stack)->next;
	(*stack)->next = NULL;
	buffer_last->next = buffer_first;
	*stack = buffer_last;
	if (mouv_name[0] != '\0')
		ft_printf("%s\n", mouv_name);
}

void	mv_rrr(t_stack **stackA, t_stack **stackB)
{
	mv_reverse_rotate(stackA, "\0");
	mv_reverse_rotate(stackB, "\0");
	ft_printf("rrr\n");
}