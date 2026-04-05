/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:35:03 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 22:01:06 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	print_error(char *str)
{
	ft_printf("Pushswap error : %s\n", str);
}

int	main(int ac, char **av)
{
	t_stack		*satck_a;
	t_stack		*satck_b;

	if (ac > 2)
	{
		satck_a = NULL;
		satck_b = NULL;
		if (check_input(av))
			return (1);
		if (fillsatck_a(av, &satck_a))
			return (1);
		which_algo(&satck_a, &satck_b);
		free_stack(&satck_a);
		free_stack(&satck_b);
		return (0);
	}
	return (1);
}
