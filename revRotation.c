/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revRotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:51:24 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 00:45:46 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rev_rotation(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_end;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = *stack;
	before_end = NULL;
	while (tail->next != NULL)
	{
		before_end = tail;
		tail = tail->next;
	}
	before_end->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_stack **stack_a)
{
	rev_rotation(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rev_rotation(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotation(stack_a);
	rev_rotation(stack_b);
	write(1, "rrr\n", 4);
}
