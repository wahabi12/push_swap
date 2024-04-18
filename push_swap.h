/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:43:05 by blatifat          #+#    #+#             */
/*   Updated: 2024/04/18 08:07:45 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h> 
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				stack_cost_a;
	int				stack_cost_b;
	int				obj_position;
	int				position;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	find_smallest_move(t_stack *stack_b, int *cheapest,
			int *stack_cost_a, int *stack_cost_b);
int		main(int argc, char **argv);
int		identif_input(char **args);
int		identif_zero(char *args);
int		identif_duplicate(char **args);
int		check_dup_num(char **argv);
int		strcmp(const char *s1, const char *s2);
int		check_num_validity(char *args);
void	update_position(t_stack **stack);
int		find_target(t_stack **stack_a, int bIndex,
			int indice_init, int obj_position);
void	calculat_target_position(t_stack **a, t_stack **b);
void	sort(t_stack **stack_a, t_stack **stack_b);
int		sorted(t_stack *stack);
int		find_max_num(t_stack *stack);
void	sort_3(t_stack **stack);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	set_index(t_stack *stack_a, int stack_size);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int staackSize);
void	rev_rot_both(t_stack **a, t_stack **b,
			int *stack_cost_a, int *stack_cost_b);
void	rot_both(t_stack **a, t_stack **b,
			int *stack_cost_a, int *stack_cost_b);
void	rot_a(t_stack **a, int *price);
void	rot_b(t_stack **b, int *price);
void	mouvement(t_stack **a, t_stack **b, int stack_cost_a, int stack_cost_b);
void	rev_rotation(t_stack **stack);
void	calculat_prices(t_stack **stack_a, t_stack **stack_b);
void	optimal_move(t_stack **stack_a, t_stack **stack_b);
int		search_lowest_index_position(t_stack **stack);
long	ft_atol(const char *str);
void	rotation(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
void	swap(t_stack *stack);
int		stack_lenght(t_stack *stack);
void	adjust_stack(t_stack **stack_a);
void	move_stack_a3_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);
void	error(t_stack **stack_a, t_stack **stack_b);
void	insert_at_end(t_stack **stack, t_stack *new);
t_stack	*create_new_stack(int nbr);
t_stack	*new_stack_value(int argc, char **argv);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_a);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif