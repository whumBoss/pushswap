/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:56:10 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/06 16:23:28 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_stack(t_stack *stack_a)
{
	printf("\n\n------- Verif struct -------\n\n");
	if (stack_a == NULL)
		printf("NULL\n");
	while (stack_a)
	{
		printf("NODE\n");
		printf("node->value = %d\n", stack_a->value);
		printf("node->index = %d\n", stack_a->index);
		printf("node->next = %p\n", stack_a->next);
		printf("node's adress = %p\n", stack_a);
		printf("pointeur's adress = %p\n", &stack_a);
		stack_a = stack_a->next;
	}
}
