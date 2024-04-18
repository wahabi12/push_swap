/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:54:58 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 07:56:37 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if ((argc < 2) || !identif_input(argv) || !check_dup_num(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_b = NULL;
	stack_a = new_stack_value(argc, argv);
	stack_size = stack_lenght(stack_a);
	set_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
