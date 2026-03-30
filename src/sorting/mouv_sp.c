/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 21:18:06 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/30 22:57:20 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
/*
swap : 
sa -> swap the first 2 nodes in stackA (soit 23 et 12)  V
sb -> swap the first 2 nodes in stackB (soit 11 et -60)  V
ss -> swap the first 2 nodes in stackA et stackB (soit sa et sb en mm tmps)  X
*/

/*
push :
pa -> push first node of stackB in stackA  V
pb -> push first node of stackA in stackB  V
*/
void	mv_swap(t_stack **stack, char *mouv_name)
{
	t_stack	*buffer;
	
	buffer = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	buffer->next = *stack;
	*stack = buffer;
	if (mouv_name[0] != '\0')
		ft_printf("%s\n", mouv_name);
}

void	mv_sswap(t_stack **stackA, t_stack **stackB)
{
	mv_swap(stackA, "\0");
	mv_swap(stackB, "\0");
	ft_printf("ss\n");
}

void	mv_push(t_stack **stack_origin, t_stack **stack_destination, char *mouv_name)
{
	t_stack	*buffer;
	buffer = *stack_origin;
	*stack_origin = (*stack_origin)->next;
	if (!*stack_destination)
		buffer->next = NULL;
	else
		buffer->next = *stack_destination;
	*stack_destination = buffer;
	ft_printf("%s\n", mouv_name);
}