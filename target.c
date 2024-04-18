/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:26:14 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 08:29:02 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack **stack)
{
	t_stack	*current;
	int		pos_actuel;

	current = *stack;
	pos_actuel = 0;
	while (current != NULL)
	{
		current->position = pos_actuel;
		current = current->next;
		pos_actuel++;
	}
}

int	find_target(t_stack **a, int bIndex,
							int indice_init, int obj_position)
{
	t_stack	*cur_a;

	cur_a = *a;
	while (cur_a)
	{
		if (cur_a->index > bIndex && cur_a->index < indice_init)
		{
			indice_init = cur_a->index;
			obj_position = cur_a->position;
		}
		cur_a = cur_a->next;
	}
	if (indice_init != INT_MAX)
		return (obj_position);
	cur_a = *a;
	while (cur_a)
	{
		if (cur_a->index < indice_init)
		{
			indice_init = cur_a->index;
			obj_position = cur_a->position;
		}
		cur_a = cur_a->next;
	}
	return (obj_position);
}

void	calculat_target_position(t_stack **a, t_stack **b)
{
	t_stack	*current_b;
	int		obj_position;

	current_b = *b;
	update_position(a);
	update_position(b);
	obj_position = 0;
	while (current_b)
	{
		obj_position = find_target(a, current_b->index, INT_MAX, obj_position);
		current_b->obj_position = obj_position;
		current_b = current_b->next;
	}
}
