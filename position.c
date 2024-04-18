/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:37:54 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 02:39:55 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_lowest_index_position(t_stack **stack)
{
	t_stack	*current;
	int		min_pos;
	int		min_index;
	int		current_pos;

	current = *stack;
	min_index = INT_MAX;
	min_pos = -1;
	current_pos = 0;
	while (current != NULL)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}
