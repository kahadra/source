/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:17:47 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:19 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	something_in_top_a(t_var *var, t_stack_node *top, t_stack_node *max, t_stack_node *min)
{
	if (max == top->down)
	{
		save_list(var, sa(var));
		save_list(var, ra(var));
		save_list(var, sa(var));
		save_list(var, rra(var));
		if (top->down->val > top->down->down->val)
			save_list(var, sa(var));
	}
	if (min == top->down)
	{
		save_list(var, ra(var));
		if (top->down->val > top->down->down->val)
			save_list(var, sa(var));
		save_list(var, rra(var));
	}
}

static void	something_in_bottom_a(t_var *var, t_stack_node *top, t_stack_node *min)
{
	if (top->down->val > top->down->down->val)
		save_list(var, sa(var));
	if (min == top->down->down->down)
	{
		save_list(var, ra(var));
		save_list(var, sa(var));
		save_list(var, rra(var));
		save_list(var, sa(var));
	}
}

void	sort_three_a(t_var *var)
{
	t_stack_node	*top;
	t_stack_node	*max;
	t_stack_node	*min;

	top = var->stack_a->top;
	if (is_sorted(top->down, 3, S_A))
		return ;
	max = max_node(top->down, 3);
	min = min_node(top->down, 3);
	if (max == top->down || min == top->down)
		something_in_top_a(var, top, max, min);
	else if (max == top->down->down->down
		|| min == top->down->down->down)
		something_in_bottom_a(var, top, min);
}
