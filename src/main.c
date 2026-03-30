/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:35:03 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/30 22:32:34 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
/*
la fonction check args
la fonction printError juste write la sortie d'erreur
*/
void	printError(char *str)
{
	ft_printf("Pushswap error : %s\n", str);
}

int		main(int ac, char **av)
{
	if (ac > 2)
	{
		t_stack		*stackA;
		t_stack		*stackB;

		stackA = NULL;
		stackB = NULL;
		if (checkInput(av))
			return (1);
		if (fillStackA(av, &stackA))
			return (1);
		// PrintStack(stackA);
		mv_push(&stackA, &stackB, "pb");
		mv_push(&stackA, &stackB, "pb");
		mv_push(&stackA, &stackB, "pb");
		PrintStack(stackA);
		PrintStack(stackB);
		/*
		algo
		*/
		free_stack(&stackA);
		free_stack(&stackB);
		return (0);
	}
	printError("expected 2 arg");
	return (1);
}