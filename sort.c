/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:12:12 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 08:02:22 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	move_stack_a3_to_stack_b(stack_a, stack_b);
	sort_3(stack_a);
	if (sorted(*stack_b))
		sb(stack_b);
	while (*stack_b)
	{
		calculat_target_position(stack_a, stack_b);
		calculat_prices(stack_a, stack_b);
		optimal_move(stack_a, stack_b);
	}
	if (!sorted(*stack_a))
		adjust_stack(stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	move_stack_a3_to_stack_b(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		calculat_target_position(stack_a, stack_b);
		calculat_prices(stack_a, stack_b);
		optimal_move(stack_a, stack_b);
	}
	if (!sorted(*stack_a))
		adjust_stack(stack_a);
}
