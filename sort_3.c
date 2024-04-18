/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:30:45 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 07:53:00 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_max_num(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	sort_3(t_stack **stack)
{
	int	max_index;

	if (sorted(*stack))
		return ;
	max_index = find_max_num(*stack);
	if ((*stack)->index == max_index)
		ra(stack);
	else if ((*stack)->next->index == max_index)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
