/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:30:40 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:33 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_piv_idx_b(int size, int pre_piv_idx)
{
	int	gap;

	if (size <= 3)
		return (pre_piv_idx - 1);
	gap = size / 2;
	return (pre_piv_idx - gap);
}

static void	re_rotate(t_var *var, int size, int count)
{
	if (get_stack_size(var->stack_b) != size)
		while (count--)
			save_list(var, rrb(var));
}

static int	send_half_element_b(t_var *var, int piv, int pre_size)
{
	int	size;
	int	post_size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = get_available_stack_size_b(pre_size);
	post_size = get_available_stack_size_a(size);
	while (size-- && answer < post_size)
	{
		if (var->stack_b->top->down->val > piv)
		{
			answer++;
			save_list(var, pa(var));
		}
		else
		{
			count++;
			save_list(var, rb(var));
		}
	}
	re_rotate(var, size, count);
	return (answer);
}

static int	check_size_and_sort(t_var *var, int size)
{
	t_stack_node	*top;

	top = var->stack_b->top;
	if (size <= 4)
	{
		if (size == 2
			&& top->down->val < top->down->down->val)
			save_list(var, sb(var));
		else if (size == 3 && get_stack_size(var->stack_b) != size)
			sort_three_b(var);
		else if (size == 3 && get_stack_size(var->stack_b) == size)
			sort_three_only_b(var);
		else if (size == 4)
		{
			if (get_stack_size(var->stack_b) == size)
				sort_four_only_b(var);
			else
				sort_four_b(var);
		}
	}
	if (is_sorted(top->down, size, S_B))
		return (1);
	return (0);
}

void	re_b(t_var *var, int pre_size, int pre_piv_idx)
{
	int		now_piv_index;
	int		size;
	int		send_count;

	size = get_available_stack_size_b(pre_size);
	if (check_size_and_sort(var, size))
		return ;
	now_piv_index = get_piv_idx_b(size, pre_piv_idx);
	send_count = send_half_element_b(var,
			var->piv_arr[now_piv_index], pre_size);
	re_a(var, size, now_piv_index);
	re_b(var, size, now_piv_index);
	while (send_count--)
		save_list(var, pb(var));
}
