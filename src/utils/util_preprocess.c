/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_preprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:43:28 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:43:11 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	piv;
	int	i;
	int	j;

	if (start >= end)
		return ;
	piv = start;
	i = start + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[piv])
			i++;
		while (j > start && arr[j] >= arr[piv])
			j--;
		if (i > j)
			swap(arr, j, piv);
		else
			swap(arr, i, j);
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void	check_duplication(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		if (arr[i] == arr[j])
			ft_error();
		i++;
	}
}
