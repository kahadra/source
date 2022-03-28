/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:59:31 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:41 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*new_stack_node(int num)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (0);
	node->val = num;
	node->up = NULL;
	node->down = NULL;
	return (node);
}

void	init_stack(t_var *var)
{
	var->stack_a = malloc(sizeof(t_stack));
	var->stack_b = malloc(sizeof(t_stack));
	var->stack_a->top = new_stack_node(0);
	var->stack_a->bottom = new_stack_node(0);
	var->stack_a->top->down = var->stack_a->bottom;
	var->stack_a->bottom->up = var->stack_a->top;
	var->stack_b->top = new_stack_node(0);
	var->stack_b->bottom = new_stack_node(0);
	var->stack_b->top->down = var->stack_b->bottom;
	var->stack_b->bottom->up = var->stack_b->top;
}

void	push_top(t_stack *stack, t_stack_node *new_node)
{
	t_stack_node	*top;
	t_stack_node	*temp;

	top = stack->top;
	temp = top->down;
	top->down = new_node;
	temp->up = new_node;
	new_node->up = top;
	new_node->down = temp;
}

void	push_bottom(t_stack *stack, t_stack_node *new_node)
{
	t_stack_node	*bottom;
	t_stack_node	*temp;

	bottom = stack->bottom;
	temp = bottom->up;
	bottom->up = new_node;
	temp->down = new_node;
	new_node->up = temp;
	new_node->down = bottom;
}

t_stack_node	*pop_top(t_stack *stack)
{
	t_stack_node	*top;
	t_stack_node	*temp;

	top = stack->top;
	if (top->down == stack->bottom)
		return (0);
	temp = top->down;
	temp->down->up = top;
	top->down = temp->down;
	temp->up = NULL;
	temp->down = NULL;
	return (temp);
}
