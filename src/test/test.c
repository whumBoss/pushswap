/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:56:10 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/04 16:14:34 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	PrintStack(t_stack *stackA)
{
	printf("\n\n------- Verif struct -------\n\n");
	if (stackA == NULL)
	printf("NULL\n");
	while (stackA)
	{
		printf("NODE\n");
		printf("node->value = %d\n", stackA->value);
		printf("node->index = %d\n", stackA->index);
		printf("node->next = %p\n", stackA->next);
		printf("node's adress = %p\n", stackA);
		printf("pointeur's adress = %p\n", &stackA);
		stackA = stackA->next;
	}
}