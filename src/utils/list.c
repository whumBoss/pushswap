/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:07 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/06 16:42:41 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	size_list(t_stack *stack_a)
{
	int	size;

	size = 0;
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		size++;
	}
	return (size);
}

t_stack	*create_node(char *arg)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (ft_printf("Error\n"), NULL);
	new_node->index = 0;
	new_node->value = atoi(arg);
	new_node->next = NULL;
	return (new_node);
}

int	pushback(char *arg, t_stack **head)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = create_node(arg);
	if (!new_node)
		return (1);
	if (!*head)
	{
		*head = new_node;
		return (0);
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	return (0);
}
