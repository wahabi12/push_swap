/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setIndex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:24:00 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 03:43:41 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack_a, int stack_size)
{
	int		index;
	t_stack	*highest;
	t_stack	*ptr;
	int		nbr;

	index = stack_size - 1;
	while (index >= 0)
	{
		ptr = stack_a;
		highest = NULL;
		nbr = INT_MIN;
		while (ptr)
		{
			if (ptr->nbr > nbr && ptr->index == 0)
			{
				highest = ptr;
				nbr = ptr->nbr;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = index;
		index--;
	}
}
