/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:55:34 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:36 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	something_in_top_b(t_var *var, t_stack_node *top, t_stack_node *max, t_stack_node *min)
{
	if (max == top->down)
	{
		save_list(var, rb(var));
		if (top->down->val < top->down->down->val)
			save_list(var, sb(var));
		save_list(var, rrb(var));
	}
	if (min == top->down)
	{
		save_list(var, sb(var));
		save_list(var, rb(var));
		save_list(var, sb(var));
		save_list(var, rrb(var));
		if (top->down->val < top->down->down->val)
			save_list(var, sb(var));
	}
}

static void	something_in_bottom_b(t_var *var, t_stack_node *top, t_stack_node *max)
{
	if (top->down->val < top->down->down->val)
		save_list(var, sb(var));
	if (max == top->down->down->down)
	{
		save_list(var, rb(var));
		save_list(var, sb(var));
		save_list(var, rrb(var));
		save_list(var, sb(var));
	}
}

void	sort_three_b(t_var *var)
{
	t_stack_node	*top;
	t_stack_node	*max;
	t_stack_node	*min;

	top = var->stack_b->top;
	if (is_sorted(top->down, 3, S_B))
		return ;
	max = max_node(top->down, 3);
	min = min_node(top->down, 3);
	if (max == top->down || min == top->down)
		something_in_top_b(var, top, max, min);
	else if (max == top->down->down->down
		|| min == top->down->down->down)
		something_in_bottom_b(var, top, max);
}
