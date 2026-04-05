/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:19 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 22:19:16 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	assign_index(t_stack **satck_a)
{
	int		index;
	t_stack	*compare_satck_a;
	t_stack	*current_node;

	current_node = *satck_a;
	while (current_node)
	{
		index = 0;
		compare_satck_a = *satck_a;
		while (compare_satck_a)
		{
			if (compare_satck_a->value < current_node->value)
				index++;
			compare_satck_a = compare_satck_a->next;
		}
		current_node->index = index;
		current_node = current_node->next;
	}
}

int	verif_doublon(t_stack *satck_a)
{
	t_stack	*copystack;
	int		buffer;

	buffer = satck_a->value;
	copystack = satck_a;
	while (copystack->next != NULL)
	{
		while (copystack->next != NULL)
		{
			copystack = copystack->next;
			if (buffer == copystack->value)
				return (1);
		}
		copystack = satck_a;
		while (buffer != copystack->value)
			copystack = copystack->next;
		copystack = copystack->next;
		buffer = copystack->value;
	}
	return (0);
}

int	sorted_or_not(t_stack *satck_a)
{
	t_stack	*copy;

	copy = satck_a;
	while (copy->next != NULL)
	{
		if (copy->value > copy->next->value)
			return (0);
		copy = copy->next;
	}
	return (1);
}

int	filling_stack(char **av, t_stack **satck_a)
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
			return (print_error("arg allocation gone wrong (split)"), 1);
		while (arg[j])
		{
			if (pushback(arg[j], satck_a))
				return (free_stack(satck_a), 1);
			j++;
		}
		free_tab(arg);
		i++;
	}
	return (0);
}

int	fillsatck_a(char **av, t_stack **satck_a)
{
	t_stack	*copy;

	filling_stack(av, satck_a);
	copy = (*satck_a)->next;
	free(*satck_a);
	*satck_a = copy;
	if (verif_doublon(*satck_a))
		return (print_error("args are identical values"), 1);
	if (sorted_or_not(*satck_a))
		return (print_error("already sorted"), 1);
	assign_index(satck_a);
	return (0);
}
