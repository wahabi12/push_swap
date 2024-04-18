/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatStack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:50:16 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 08:26:23 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_at_end(t_stack **stack, t_stack *new)
{
	t_stack	*last_node;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new;
}

t_stack	*create_new_stack(int nbr)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->nbr = nbr;
	new_stack->index = 0;
	new_stack->position = -1;
	new_stack->obj_position = -1;
	new_stack->stack_cost_a = -1;
	new_stack->stack_cost_b = -1;
	new_stack->next = NULL;
	return (new_stack);
}

t_stack	*new_stack_value(int argc, char **argv)
{
	t_stack		*stack_a;
	int			i;
	long int	num;
	t_stack		*new_node;

	stack_a = NULL;
	i = 1;
	if (argc <= 1)
		return (NULL);
	num = ft_atol(argv[i]);
	if (num > INT_MAX || num < INT_MIN)
		error(&stack_a, NULL);
	stack_a = create_new_stack((int)num);
	i++;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error(&stack_a, NULL);
		new_node = create_new_stack((int)num);
		insert_at_end(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}
