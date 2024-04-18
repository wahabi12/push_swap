/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveRot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:45:11 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 00:48:46 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rotation(t_stack **stack)
{
	t_stack	*temp_value;
	t_stack	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp_value = *stack;
	*stack = (*stack)->next;
	last_node = temp_value;
	while (last_node->next != NULL)
		last_node = last_node->next;
	temp_value->next = NULL;
	last_node->next = temp_value;
}

void	ra(t_stack **stack_a)
{
	rotation(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotation(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotation(stack_a);
	rotation(stack_b);
	write(1, "rr\n", 3);
}
