/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:56:10 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/26 23:14:58 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	testFillStack(t_stack *stackA)
{
	printf("------- Verif struct -------\n\n");
	while (stackA->next != NULL)
	{
		stackA = stackA->next;
		printf("NODE\n");
		printf("node->value = %d\n", stackA->value);
		printf("node->next = %p\n", stackA->next);
		printf("node's adress = %p\n", &stackA);
	}
}