/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movePush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:38:41 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 00:34:48 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*current;

	if (*src == NULL)
		return ;
	current = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = current;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
