/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:56:10 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 22:08:14 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_stack(t_stack *satck_a)
{
	printf("\n\n------- Verif struct -------\n\n");
	if (satck_a == NULL)
		printf("NULL\n");
	while (satck_a)
	{
		printf("NODE\n");
		printf("node->value = %d\n", satck_a->value);
		printf("node->index = %d\n", satck_a->index);
		printf("node->next = %p\n", satck_a->next);
		printf("node's adress = %p\n", satck_a);
		printf("pointeur's adress = %p\n", &satck_a);
		satck_a = satck_a->next;
	}
}
