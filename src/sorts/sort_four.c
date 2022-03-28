/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:30:42 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:35 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_a(t_var *var)
{
	t_stack_node	*top;
	t_stack_node	*max;
	t_stack_node	*min;

	top = var->stack_a->top;
	if (is_sorted(top->down, 4, S_A))
		return ;
	max = max_node(top->down, 4);
	min = min_node(top->down, 4);
	if (min == top->down)
	{
		save_list(var, ra(var));
		sort_three_a(var);
		save_list(var, rra(var));
	}
	else if (max == top->down->down->down->down)
		sort_three_a(var);
}

void	sort_four_b(t_var *var)
{
	t_stack_node	*top;
	t_stack_node	*max;
	t_stack_node	*min;

	top = var->stack_b->top;
	if (is_sorted(top->down, 4, S_B))
		return ;
	max = max_node(top->down, 4);
	min = min_node(top->down, 4);
	if (min == top->down)
	{
		save_list(var, rb(var));
		sort_three_b(var);
		save_list(var, rrb(var));
	}
	else if (max == top->down->down->down->down)
		sort_three_b(var);
}
