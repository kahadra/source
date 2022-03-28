/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:36:20 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:39 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_node	*new_list_node(char *str)
{
	t_list_node	*node;

	node = malloc(sizeof(t_list_node));
	if (!node)
		return (0);
	node->val = str;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	init_list(t_var *var)
{
	var->list = malloc(sizeof(t_list));
	var->list->head = new_list_node("");
}

static void	list_append(t_list *list, t_list_node *node)
{
	t_list_node	*temp;

	temp = list->head;
	while (temp->right != NULL)
		temp = temp->right;
	temp->right = node;
	node->left = temp;
	node->right = NULL;
}

void	save_list(t_var *var, char *str)
{
	t_list_node	*new_node;

	new_node = new_list_node(str);
	list_append(var->list, new_node);
}

void	print_list(t_var *var)
{
	t_list_node	*temp;

	temp = var->list->head;
	while (temp != NULL)
	{
		if (temp->val != NULL)
			ft_putstr(temp->val, 1);
		temp = temp->right;
	}
}
