/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:07 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/28 19:49:12 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	size_list(t_stack *stackA)
{
	int	size;
	
	size = 0;
	while (stackA->next != NULL)
	{
		stackA = stackA->next;
		size++;
	}
	return (size);
}

t_stack	*create_node(char *arg)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (printError ("node allocation gone wrong"), NULL);
	new_node->index = 0;
	new_node->value = atoi(arg);
	new_node->next = NULL;
	return(new_node);
}

int	pushback(char *arg, t_stack **head)
{
	t_stack	*new_node;

	new_node = create_node(arg);
	if (!new_node)
		return (1);
	if (!*head)
	{
		*head = new_node;
		return (0);
	}
	t_stack	*current;
	
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	return (0);
}
	/*
	si list doublement chainee
	insert_at_head
	new_node = create_node(arg);
	head->next = new_node;
	new_node->prev = head;
	*/
