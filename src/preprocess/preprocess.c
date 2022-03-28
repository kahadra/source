/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:26:39 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:46:10 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sorted(t_var *var)
{
	int				i;
	t_stack_node	*temp;

	i = 0;
	temp = var->stack_a->top->down;
	while (i < var->max_size)
	{
		if (var->piv_arr[i] != temp->val)
			return ;
		i++;
		temp = temp->down;
	}
	if (i == var->max_size)
		exit(0);
}

static void	put_piv_arr(t_var *var)
{
	int				i;
	t_stack_node	*temp;

	i = 0;
	var->piv_arr = (int*)malloc(sizeof(int) * var->max_size);
	temp = var->stack_a->top->down;
	while (i < var->max_size && temp != var->stack_a->bottom)
	{
		var->piv_arr[i] = temp->val;
		temp = temp->down;
		i++;
	}
	quick_sort(var->piv_arr, 0, var->max_size - 1);
}

static int	ft_atoi(char *start, char *end)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (end - start > 11)
		ft_error();
	while (start < end && ((*start >= 9 && *start <= 13) || *start == 32))
		start++;
	if (start < end && (*start == '+' || *start == '-'))
	{
		if (*start == '-')
			sign *= -1;
		start++;
	}
	while (start < end && !(*start < '0' || *start > '9'))
		num = num * 10 + (*(start++) - '0');
	if (start < end && (*start < '0' || *start > '9'))
			ft_error();
	if (num * sign < INT_MIN || num * sign > INT_MAX)
		ft_error();
	return (num * sign);
}

static int	argv_parser(t_var *var, char *str, int len)
{
	int		i;
	int		atoi_result;
	int		count;
	char	*start;
	char	*end;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		{
			start = &(str[i]);
			while (str[i] && !((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
				i++;
			end = &(str[i]);
			atoi_result = ft_atoi(start, end);
			count++;
			push_bottom(var->stack_a, new_stack_node(atoi_result));
		}
		i++;
	}
	return (count);
}

void	preprocess(t_var *var, int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += argv_parser(var, argv[i], ft_strlen(argv[i]));
		i++;
	}
	var->max_size = count;
	put_piv_arr(var);
	check_duplication(var->piv_arr, var->max_size);
	check_sorted(var);
}
