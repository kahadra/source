/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:52:04 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:40 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *temp, int len, int now_stack)
{
	int	i;

	i = 0;
	if (now_stack == S_A)
	{
		while (i < len - 1)
		{
			if (temp->val > temp->down->val)
				return (0);
			temp = temp->down;
			i++;
		}
		return (1);
	}
	else
	{
		while (i < len - 1)
		{
			if (temp->val < temp->down->val)
				return (0);
			temp = temp->down;
			i++;
		}
		return (1);
	}
}

t_stack_node	*max_node(t_stack_node *temp, int len)
{
	int				i;
	t_stack_node	*max_node;

	i = 0;
	max_node = temp;
	temp = temp->down;
	while (i < len - 1)
	{
		if (temp->val > max_node->val)
			max_node = temp;
		i++;
		temp = temp->down;
	}
	return (max_node);
}

t_stack_node	*min_node(t_stack_node *temp, int len)
{
	int				i;
	t_stack_node	*min_node;

	i = 0;
	min_node = temp;
	temp = temp->down;
	while (i < len - 1)
	{
		if (temp->val < min_node->val)
			min_node = temp;
		i++;
		temp = temp->down;
	}
	return (min_node);
}
