/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 21:18:06 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/29 22:10:10 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
/*
swap : 
sa -> swap the first 2 nodes in stackA (soit 23 et 12)
sb -> swap the first 2 nodes in stackB (soit 11 et -60)
ss -> swap the first 2 nodes in stackA et stackB (soit sa et sb en mm tmps)
*/

/*
push :
pa -> push first node of stackB in stackA
pb -> push first node of stackA in stackB
*/

void	mv_push(t_stack **stack_origin, t_stack **stack_destination)
{
	t_stack	*copy_origin;
	t_stack	*copy_destination;
	copy_origin = *stack_origin;
	copy_origin = copy_origin->next;
	copy_destination = *stack_destination;
	copy_destination = copy_destination->next;
	(*stack_origin)->next = copy_destination;
}