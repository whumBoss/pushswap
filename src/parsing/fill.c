/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:19 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/02 19:06:58 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	assign_index(t_stack **stackA)
{
	int		index;
	t_stack	*compare_stackA;
	t_stack	*current_node;

	current_node = *stackA;
	//current_node = current_node->next;
	while (current_node)
	{
		index = 0;
		compare_stackA = *stackA;
		while (compare_stackA)
		{
			if (compare_stackA->value < current_node->value)
				index++;
			compare_stackA = compare_stackA->next;
		}
		current_node->index = index;
		current_node = current_node->next;
	}
}

int	verif_doublon(t_stack *stackA)
{
	t_stack	*copystack;
	int		buffer;
	
	buffer = stackA->value;
	copystack = stackA;
	while (copystack->next != NULL)
	{
		while (copystack->next != NULL)
		{
			copystack = copystack->next;
			if (buffer == copystack->value)
				return (1);
		}
		copystack = stackA;
		while (buffer != copystack->value)
			copystack = copystack->next;
		copystack = copystack->next;
		buffer = copystack->value;
	}
	return (0);
}

int	sorted_or_not(t_stack *stackA)
{
	t_stack	*copy;

	copy = stackA;
	while (copy->next != NULL)
	{
		if (copy->value > copy->next->value)
			return (0);
		copy = copy->next;
	}
	return (1);
}

int	fillStackA(char **av, t_stack **stackA)
{
	int		i;
	int		j;
	char	**arg;

	i = 0;

	while (av[i])
	{
		j = 0;
		arg = ft_split(av[i], ' ');
		if (!arg)
			return (printError("arg allocation gone wrong (split)"), 1);
		while (arg[j])
		{
			if (pushback(arg[j], stackA))
				return (free_stack(stackA), 1);
			j++;
		}
		free_tab(arg);
		i++;
	}
	*stackA = (*stackA)->next;
	if (verif_doublon(*stackA))
		return (printError("args are identical values"), 1);
	if (sorted_or_not(*stackA))
		return (printError("already sorted"), 1);
	assign_index(stackA);
	return (0);
}
