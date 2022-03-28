/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_only.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:33:32 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:35 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_four_a_realization(t_var *var) // bottom을 추가했음
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	t_stack_node	*min;

	top = var->stack_a->top;
	bottom = var->stack_a->bottom;
	min = min_node(top->down, 4);
	sort_three_a(var);
	if (min == bottom->up)
		save_list(var, rra(var));
}

static void	sort_four_b_realization(t_var *var) // bottom을 추가했음
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	t_stack_node	*max;

	top = var->stack_b->top;
	bottom = var->stack_b->bottom;
	max = max_node(top->down, 4);
	sort_three_b(var);
	if (max == bottom->up)
		save_list(var, rrb(var));
}

void	sort_four_only_a(t_var *var) //47번줄 bottom추가함
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	t_stack_node	*max;
	t_stack_node	*min;

	top = var->stack_a->top;
	bottom = var->stack_a->bottom;
	if (is_sorted(top->down, 4, S_A))
		return ;
	max = max_node(top->down, 4);
	min = min_node(top->down, 4);
	if (max == top->down || min == top->down)
	{
		save_list(var, ra(var));
		sort_four_a_realization(var);
	}
	else if (max == bottom->up || min == bottom->up)
		sort_four_a_realization(var);
	else
	{
		save_list(var, rra(var));
		sort_four_a_realization(var);
	}
}

void	sort_four_only_b(t_var *var)
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	t_stack_node	*max;
	t_stack_node	*min;

	top = var->stack_b->top;
	bottom = var->stack_b->bottom;
	if (is_sorted(top->down, 4, S_B))
		return ;
	max = max_node(top->down, 4);
	min = min_node(top->down, 4);
	if (max == top->down || min == top->down)
	{
		save_list(var, rb(var));
		sort_four_b_realization(var);
	}
	else if (max == bottom->up || min == bottom->up)
		sort_four_b_realization(var);
	else
	{
		save_list(var, rrb(var));
		sort_four_b_realization(var);
	}
}

