/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:34:56 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/27 15:57:02 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
taper les 3 fonctions de check

ftIsAlpha
reprendre ft_isalpha de la libft et le custom pour que il accepte rien sauf des chiffre des signe et que il dois prendre un tableau en entree

checkSign
signe seul, plusieurs signe en premier et signe ds le nb

checkLimits
atoi et verif si le nb <= INTMAX && nb >= INTMIN
*/

int	checkLimits(char *arg)
{
	long		value;

	value = ft_atoi(arg);
	if (value > INTMAX || value < INTMIN)
		return (1);
	return (0);
}

int	checkSign(char *arg)
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

int	ftIsDigit(char *arg)
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

int	checkArg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ftIsDigit(arg[i]))
			return (1);
		if (checkSign(arg[i]))
			return (1);
		if (checkLimits(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	checkInput(char **av)
{
	int		i;
	char	**arg;

	i = 1;
	while (av[i])
	{
		arg = ft_split(av[i], ' ');
		if (checkArg(arg))
			return (1);
		i++;
	}
	return (0);
}