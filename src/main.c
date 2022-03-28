/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:39:48 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:46:35 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	send_half_element_init(t_var *var, int piv)
{
	int	size;
	int	i;

	i = 0;
	size = var->max_size;
	while (i < size)
	{
		if (var->stack_a->top->down->val <= piv)
			save_list(var, pb(var));
		else
			save_list(var, ra(var));
		i++;
	}
	return (0);
}

static int	check_size_and_sort(t_var *var)
{
	t_stack_node	*top;

	top = var->stack_a->top;
	if (var->max_size <= 4)
	{
		if (var->max_size == 2 && (top->down->val > top->down->down->val))
			save_list(var, sa(var));
		else if (var->max_size == 3)
			sort_three_only_a(var);
		else if (var->max_size == 4)
			sort_four_only_a(var);
	}
	if (is_sorted(top->down, var->max_size, S_A))
		return (1);
	return (0);
}

static void	re(t_var *var)
{
	int	now_piv_index;
	int	size;
	int	i;

	if (check_size_and_sort(var))
		return ;
	now_piv_index = var->max_size / 2;
	if (var->max_size % 2 == 0)
		now_piv_index -= 1;
	send_half_element_init(var, var->piv_arr[now_piv_index]);
	re_a(var, var->max_size, now_piv_index);
	re_b(var, var->max_size, now_piv_index);
	size = var->max_size / 2;
	if (var->max_size % 2 == 1)
		size += 1;
	i = 0;
	while (i++ < size)
		save_list(var, pa(var));
}

int main(int argc, char *argv[])
{
	t_var	var;

	if (argc >= 2)
	{
		init_stack(&var);
		init_list(&var);
		preprocess(&var, argc, argv);
		re(&var);
		optimize_list(var.list);
		print_list(&var);
		exit(0);
	}
	return (0);
}
