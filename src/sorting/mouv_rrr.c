/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 21:18:29 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 22:12:48 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	mv_rotate(t_stack **stack, char *mouv_name)
{
	t_stack	*buffer_last;
	t_stack	*buffer_first;

	if ((*stack)->next == NULL)
		return ;
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

void	mv_rr(t_stack **satck_a, t_stack **satck_b)
{
	mv_rotate(satck_a, "\0");
	mv_rotate(satck_b, "\0");
	ft_printf("rr\n");
}

void	mv_reverse_rotate(t_stack **stack, char *mouv_name)
{
	t_stack	*buffer_first;
	t_stack	*buffer_last;

	if ((*stack)->next == NULL)
		return ;
	buffer_first = *stack;
	while ((*stack)->next->next != NULL)
		*stack = (*stack)->next;
	buffer_last = (*stack)->next;
	(*stack)->next = NULL;
	buffer_last->next = buffer_first;
	*stack = buffer_last;
	if (mouv_name[0] != '\0')
		ft_printf("%s\n", mouv_name);
}

void	mv_rrr(t_stack **satck_a, t_stack **satck_b)
{
	mv_reverse_rotate(satck_a, "\0");
	mv_reverse_rotate(satck_b, "\0");
	ft_printf("rrr\n");
}
