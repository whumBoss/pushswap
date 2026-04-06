/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:19 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/06 19:27:27 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	assign_index(t_stack **stack_a)
{
	int		index;
	t_stack	*compare_stack_a;
	t_stack	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		index = 0;
		compare_stack_a = *stack_a;
		while (compare_stack_a)
		{
			if (compare_stack_a->value < current_node->value)
				index++;
			compare_stack_a = compare_stack_a->next;
		}
		current_node->index = index;
		current_node = current_node->next;
	}
}

int	verif_doublon(t_stack *stack_a)
{
	t_stack	*copystack;
	int		buffer;

	buffer = stack_a->value;
	copystack = stack_a;
	while (copystack->next != NULL)
	{
		while (copystack->next != NULL)
		{
			copystack = copystack->next;
			if (buffer == copystack->value)
				return (1);
		}
		copystack = stack_a;
		while (buffer != copystack->value)
			copystack = copystack->next;
		copystack = copystack->next;
		buffer = copystack->value;
	}
	return (0);
}

int	sorted_or_not(t_stack *stack_a)
{
	t_stack	*copy;

	copy = stack_a;
	while (copy->next != NULL)
	{
		if (copy->value > copy->next->value)
			return (0);
		copy = copy->next;
	}
	return (1);
}

int	filling_stack(char **av, t_stack **stack_a)
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
			return (ft_printf("Error\n"), 1);
		while (arg[j])
		{
			if (pushback(arg[j], stack_a))
				return (free_stack(stack_a), 1);
			j++;
		}
		free_tab(arg);
		i++;
	}
	return (0);
}

int	fillstack_a(char **av, t_stack **stack_a)
{
	t_stack	*copy;

	filling_stack(av, stack_a);
	copy = (*stack_a)->next;
	free(*stack_a);
	*stack_a = copy;
	if (!(*stack_a)->next)
		return (1);
	if (verif_doublon(*stack_a))
		return (ft_printf("Error\n"), 1);
	if (sorted_or_not(*stack_a))
		return (1);
	assign_index(stack_a);
	return (0);
}
