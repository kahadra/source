/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:44:17 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:32 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_piv_idx_a(int size, int pre_piv_idx)
{
	int	gap;

	if (size <= 3)
		return (pre_piv_idx + 2);
	gap = size / 2;
	if (size % 2 == 1)
		gap += 1;
	return (pre_piv_idx + gap);
}

static void	re_rotate(t_var *var, int size, int count)
{
	if (get_stack_size(var->stack_a) != size)
		while (count--)
			save_list(var, rra(var));
}

static int	send_half_element_a(t_var *var, int piv, int pre_size)
{
	int	size;
	int	post_size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = get_available_stack_size_a(pre_size);
	post_size = get_available_stack_size_b(size);
	while (size-- && answer < post_size)
	{
		if (var->stack_a->top->down->val <= piv)
		{
			answer++;
			save_list(var, pb(var));
		}
		else
		{
			count++;
			save_list(var, ra(var));
		}
	}
	re_rotate(var, size, count);
	return (answer);
}

static int	check_size_and_sort(t_var *var, int size)
{
	t_stack_node	*top;

	top = var->stack_a->top;
	if (size <= 4)
	{
		if (size == 2
			&& top->down->val > top->down->down->val)
			save_list(var, sa(var));
		else if (size == 3 && get_stack_size(var->stack_a) != size)
			sort_three_a(var);
		else if (size == 3 && get_stack_size(var->stack_a) == size)
			sort_three_only_a(var);
		else if (size == 4)
		{
			if (get_stack_size(var->stack_a) == size)
				sort_four_only_a(var);
			else
				sort_four_a(var);
		}
	}
	if (is_sorted(top->down, size, S_A))
		return (1);
	return (0);
}

void	re_a(t_var *var, int pre_size, int pre_piv_idx)
{
	int		now_piv_index;
	int		size;
	int		send_count;

	size = get_available_stack_size_a(pre_size);
	if (check_size_and_sort(var, size))
		return ;
	now_piv_index = get_piv_idx_a(size, pre_piv_idx);
	send_count = send_half_element_a(var,
			var->piv_arr[now_piv_index], pre_size);
	re_a(var, size, now_piv_index);
	re_b(var, size, now_piv_index);
	while (send_count--)
		save_list(var, pa(var));
}
