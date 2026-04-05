/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:56 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 22:17:59 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	check_limits(char *arg)
{
	long		value;

	value = ft_atoi(arg);
	if (value > INTMAX || value < INTMIN)
		return (1);
	return (0);
}

int	check_sign(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '-' || arg[i] == '+')
		{
			if (arg[i + 1] == '\0')
				return (1);
			if (arg[i + 1] == '-' || arg[i + 1] == '+')
				return (1);
			if (i > 0 && (arg[i - 1] >= '0' && arg[i - 1] <= '9'))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_is_digit(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] >= 48 && arg[i] <= 57) || (arg[i] == '-' || arg[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_is_digit(arg[i]))
			return (print_error("arg is not digit"), 1);
		if (check_sign(arg[i]))
			return (print_error("sign alone or too many signs"), 1);
		if (check_limits(arg[i]))
			return (print_error("arg is over or under the limits"), 1);
		i++;
	}
	return (0);
}

int	check_input(char **av)
{
	int		i;
	char	**arg;

	i = 1;
	while (av[i])
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			return (print_error("arg allocation gone wrong (split)"), 1);
		if (check_arg(arg))
			return (1);
		free_tab(arg);
		i++;
	}
	return (0);
}
