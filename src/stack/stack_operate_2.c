/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operate_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:34:55 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:38 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ra(t_var *var)
{
	t_stack_node	*node;

	node = pop_top(var->stack_a);
	if (node)
		push_bottom(var->stack_a, node);
	return ("ra\n");
}

char	*rb(t_var *var)
{
	t_stack_node	*node;

	node = pop_top(var->stack_b);
	if (node)
		push_bottom(var->stack_b, node);
	return ("rb\n");
}

char	*rr(t_var *var)
{
	ra(var);
	rb(var);
	return ("rr\n");
}

char	*rra(t_var *var)
{
	t_stack_node	*node;

	node = pop_bottom(var->stack_a);
	if (node)
		push_top(var->stack_a, node);
	return ("rra\n");
}

char	*rrb(t_var *var)
{
	t_stack_node	*node;

	node = pop_bottom(var->stack_b);
	if (node)
		push_top(var->stack_b, node);
	return ("rrb\n");
}
