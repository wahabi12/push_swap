/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   necessaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:30:55 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 08:04:07 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strcmp(const char *s1, const char *s2)
{
	while (*s1 == '+' || *s1 == '-')
		s1++;
	while (*s2 == '+' || *s2 == '-')
		s2++;
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

long int	ft_atol(const char *str)
{
	long	num;
	int		neg;
	int		i;

	num = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * neg);
}
