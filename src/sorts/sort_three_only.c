/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:02:11 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:36 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_only_a(t_var *var) //bottom추가
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	t_stack_node	*max;
	t_stack_node	*min;

	top = var->stack_a->top;
	bottom = var->stack_a->bottom;
	if (is_sorted(top->down, 3, S_A))
		return ;
	max = max_node(top->down, 3);
	min = min_node(top->down, 3);
	if (max == bottom->up || min == bottom->up)
	{
		if (top->down->val > top->down->down->val)
			save_list(var, sa(var));
		if (min == bottom->up)
			save_list(var, rra(var));
	}
	else if (max == top->down || min == top->down)
	{
		save_list(var, ra(var));
		if (top->down->val > top->down->down->val)
			save_list(var, sa(var));
		if (min == bottom->up)
			save_list(var, rra(var));
	}
}

void	sort_three_only_b(t_var *var)
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	t_stack_node	*max;
	t_stack_node	*min;

	top = var->stack_b->top;
	bottom = var->stack_b->bottom;
	if (is_sorted(top->down, 3, S_B))
		return ;
	max = max_node(top->down, 3);
	min = min_node(top->down, 3);
	if (max == bottom->up || min == bottom->up)
	{
		if (top->down->val < top->down->down->val)
			save_list(var, sb(var));
		if (max == bottom->up)
			save_list(var, rrb(var));
	}
	else if (max == top->down || min == top->down)
	{
		save_list(var, rb(var));
		if (top->down->val < top->down->down->val)
			save_list(var, sb(var));
		if (max == bottom->up)
			save_list(var, rrb(var));
	}
}
