/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:42:41 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 01:00:09 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

void	swap(t_stack *stack)
{
	t_stack	*top;
	t_stack	*second;
	int		tmp_value;
	int		tmp_index;

	if (stack == NULL || (stack)->next == NULL)
		return ;
	top = stack;
	second = (stack)->next;
	tmp_value = top->nbr;
	top->nbr = second->nbr;
	second->nbr = tmp_value;
	tmp_index = top->index;
	top->index = second->index;
	second->index = tmp_index;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "sa\n", 3);
}
