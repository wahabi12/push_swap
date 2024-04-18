/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:20:32 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 07:55:25 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int staackSize)
{
	if (staackSize == 2 && !sorted(*stack_a))
		sa(stack_a);
	else if (staackSize == 3)
		sort_3(stack_a);
	else if (staackSize > 3 && staackSize < 6 && !sorted(*stack_a))
		sort_5(stack_a, stack_b);
	else if (staackSize > 5 && !sorted(*stack_a))
		sort(stack_a, stack_b);
}
