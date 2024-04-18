/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotMouvement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:20:06 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 00:18:36 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_both(t_stack **a, t_stack **b,
			int *stack_cost_a, int *stack_cost_b)
{
	while (*stack_cost_a < 0 && *stack_cost_b < 0)
	{
		(*stack_cost_a)++;
		(*stack_cost_b)++;
		rrr(a, b);
	}
}

void	rot_both(t_stack **a, t_stack **b, int *stack_cost_a, int *stack_cost_b)
{
	while (*stack_cost_a > 0 && *stack_cost_b > 0)
	{
		(*stack_cost_a)--;
		(*stack_cost_b)--;
		rr(a, b);
	}
}

void	rot_a(t_stack **a, int *price)
{
	while (*price)
	{
		if (*price > 0)
		{
			ra(a);
			(*price)--;
		}
		else if (*price < 0)
		{
			rra(a);
			(*price)++;
		}
	}
}

void	rot_b(t_stack **b, int *price)
{
	while (*price)
	{
		if (*price > 0)
		{
			rb(b);
			(*price)--;
		}
		else if (*price < 0)
		{
			rrb(b);
			(*price)++;
		}
	}
}

void	mouvement(t_stack **a, t_stack **b, int stack_cost_a, int stack_cost_b)
{
	if (stack_cost_a < 0 && stack_cost_a < 0)
		rev_rot_both(a, b, &stack_cost_a, &stack_cost_b);
	else if (stack_cost_a > 0 && stack_cost_b > 0)
		rot_both(a, b, &stack_cost_a, &stack_cost_b);
	rot_a(a, &stack_cost_a);
	rot_b(b, &stack_cost_b);
	pa(a, b);
}
