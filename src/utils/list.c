/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:07 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/26 23:13:08 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_stack	*create_node(char *arg)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (printError (), NULL);
	new_node->value = atoi(arg);
	//new_node->prev = NULL;
	new_node->next = NULL;
	return(new_node);
}

void	pushback(char *arg, t_stack **head)
{
	t_stack	*new_node;

	new_node = create_node(arg);
	if (!*head)
	{
		*head = new_node;
		return;
	}
	t_stack	*current;
	
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}
	/*
	si list doublement chainee
	insert_at_head
	new_node = create_node(arg);
	head->next = new_node;
	new_node->prev = head;
	*/
