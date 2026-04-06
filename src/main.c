/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:35:03 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/06 18:14:41 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		if (check_input(av))
			return (1);
		if (fillstack_a(av, &stack_a))
			return (free_stack(&stack_a), 1);
		which_algo(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
