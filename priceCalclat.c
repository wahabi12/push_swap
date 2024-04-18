/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priceCalclat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:51:13 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 08:04:11 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculat_prices(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*curent_b;

	size_a = stack_lenght(*stack_a);
	size_b = stack_lenght(*stack_b);
	curent_b = *stack_b;
	while (curent_b != NULL)
	{
		curent_b->stack_cost_b = curent_b->position;
		if (curent_b->position > size_a / 2)
			curent_b->stack_cost_b = (size_b - curent_b->position) * -1;
		curent_b->stack_cost_a = curent_b->obj_position;
		if (curent_b->obj_position > size_a / 2)
			curent_b->stack_cost_a = (size_a - curent_b->obj_position) * -1;
		curent_b = curent_b->next;
	}
}

void	find_smallest_move(t_stack *stack_b, int *cheapest,
			int *stack_cost_a, int *stack_cost_b)
{
	t_stack		*current;
	int			absolute_a;
	int			absolute_b;

	current = stack_b;
	*cheapest = INT_MAX;
	while (current != NULL)
	{
		absolute_a = current->stack_cost_a;
		if (absolute_a < 0)
			absolute_a = -absolute_a;
		absolute_b = current->stack_cost_b;
		if (absolute_b < 0)
			absolute_b = -absolute_b;
		if (absolute_a + absolute_b < *cheapest)
		{
			*cheapest = absolute_a + absolute_b;
			*stack_cost_a = current->stack_cost_a;
			*stack_cost_b = current->stack_cost_b;
		}
		current = current->next;
	}
}

void	optimal_move(t_stack **stack_a, t_stack **stack_b)
{
	int	cheapest;
	int	stack_cost_a;
	int	stack_cost_b;

	find_smallest_move(*stack_b, &cheapest, &stack_cost_a, &stack_cost_b);
	mouvement(stack_a, stack_b, stack_cost_a, stack_cost_b);
}
