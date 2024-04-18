/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a3_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:41:54 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 01:39:27 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lenght(t_stack *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	adjust_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = stack_lenght(*stack_a);
	lowest_pos = search_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	move_stack_a3_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	remaining_pushes;

	stack_size = stack_lenght(*stack_a);
	pushed = 0;
	remaining_pushes = stack_size - 3;
	while (remaining_pushes > 0)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		remaining_pushes--;
	}
	while (pushed < stack_size - 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}
