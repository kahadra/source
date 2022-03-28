/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:05:08 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:41 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*pop_bottom(t_stack *stack)
{
	t_stack_node	*bottom;
	t_stack_node	*temp;

	bottom = stack->bottom;
	if (bottom->up == stack->top)
		return (0);
	temp = bottom->up;
	temp->up->down = bottom;
	bottom->up = temp->up;
	temp->up = NULL;
	temp->down = NULL;
	return (temp);
}

int	get_stack_size(t_stack *stack)
{
	int				size;
	t_stack_node	*temp;

	size = 0;
	temp = stack->top->down;
	while (temp != stack->bottom)
	{
		size++;
		temp = temp->down;
	}
	return (size);
}

int	get_available_stack_size_a(int pre_size)
{
	int	any_size;

	any_size = pre_size / 2;
	return (any_size);
}

int	get_available_stack_size_b(int pre_size)
{
	int	any_size;

	any_size = pre_size / 2;
	if (pre_size % 2 == 1)
		any_size += 1;
	return (any_size);
}

