/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operate_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:03:50 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:37 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_var *var)
{
	t_stack_node	*temp;
	t_stack_node	*top;

	top = var->stack_a->top;
	temp = top->down;
	if (temp->down != var->stack_a->bottom)
	{
		top->down = temp->down;
		temp->down->up = temp->up;
		temp->up = temp->down;
		temp->down = temp->down->down;
		top->down->down = temp;
		temp->down->up = temp;
	}
	return ("sa\n");
}

char	*sb(t_var *var)
{
	t_stack_node	*temp1;
	t_stack_node	*temp2;
	t_stack_node	*fixed3;
	t_stack_node	*top;

	top = var->stack_b->top;
	temp1 = top->down;
	temp2 = temp1->down;
	if (temp2 != var->stack_b->bottom)
	{
		fixed3 = temp2->down;
		top->down = temp2;
		fixed3->up = temp1;
		temp1->up = temp2;
		temp1->down = fixed3;
		temp2->up = top;
		temp2->down = temp1;
	}
	return ("sb\n");
}

char	*ss(t_var *var)
{
	sa(var);
	sb(var);
	return ("ss\n");
}

char	*pa(t_var *var)
{
	t_stack_node	*node;

	node = pop_top(var->stack_b);
	if (node)
		push_top(var->stack_a, node);
	return ("pa\n");
}

char	*pb(t_var *var)
{
	t_stack_node	*node;

	node = pop_top(var->stack_a);
	if (node)
		push_top(var->stack_b, node);
	return ("pb\n");
}
