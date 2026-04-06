/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 21:18:06 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/06 16:23:28 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

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

void	mv_sswap(t_stack **stack_a, t_stack **stack_b)
{
	mv_swap(stack_a, "\0");
	mv_swap(stack_b, "\0");
	ft_printf("ss\n");
}

void	mv_push(t_stack **stack_origin, t_stack **stack_dest, char *mouv_name)
{
	t_stack	*buffer;

	buffer = *stack_origin;
	if ((*stack_origin)->next != NULL)
		*stack_origin = (*stack_origin)->next;
	else
		*stack_origin = NULL;
	if (!*stack_dest)
		buffer->next = NULL;
	else
		buffer->next = *stack_dest;
	*stack_dest = buffer;
	ft_printf("%s\n", mouv_name);
}
