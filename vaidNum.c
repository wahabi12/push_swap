/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaidNum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:29:49 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 08:05:54 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	check_num_validity(char *args)
{
	int	i;

	i = 0;
	if ((args[i] == '+' || args[i] == '-') && args[i + 1] != '\0')
		i++;
	while (args[i] != '\0')
	{
		if (!(args[i] >= '0' && args[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_dup_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
		{
			return (0);
		}
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	identif_duplicate(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i] != NULL)
	{
		j = i + 1;
		while (args[j] != NULL)
		{
			if (strcmp(args[i], args[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	identif_zero(char *args)
{
	int	i;

	i = 0;
	if (args[i] == '+' || args[i] == '-')
		i++;
	while (args[i] != '\0' && args[i] == '0')
		i++;
	if (args[i] != '\0')
		return (0);
	return (1);
}

int	identif_input(char **args)
{
	int	count_zero;
	int	i;

	i = 1;
	if (args[i] == NULL || !check_num_validity(args[i]) || args[i][0] == '\0')
		return (0);
	count_zero = identif_zero(args[i]);
	if (count_zero > 1)
		return (0);
	i++;
	while (args[i] != NULL)
	{
		if (!check_num_validity(args[i]) || (identif_zero(args[i])
				&& count_zero++ > 0) || identif_duplicate(args))
			return (0);
		i++;
	}
	return (1);
}
