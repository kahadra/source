/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:37:45 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:39 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	erase_list_node(t_list_node *earase_node)
{
	t_list_node	*temp;

	temp = earase_node->left;
	temp->right = earase_node->right->right;
	if (earase_node->right->right != NULL)
		earase_node->right->right->left = temp;
	free(earase_node->right);
	free(earase_node);
}

static void	zip_list_node(t_list_node *modify_node)
{
	t_list_node	*erase_node;

	if (cmp(modify_node->val, "ra\n") || cmp(modify_node->val, "rb\n"))
		modify_node->val = "rr\n";
	else if (cmp(modify_node->val, "rra\n") || cmp(modify_node->val, "rrb\n"))
		modify_node->val = "rrr\n";
	else if (cmp(modify_node->val, "sa\n") || cmp(modify_node->val, "sb\n"))
		modify_node->val = "ss\n";
	erase_node = modify_node->right;
	if (modify_node->right->right != NULL)
	{
		modify_node->right->right->left = modify_node;
		modify_node->right = modify_node->right->right;
	}
	else
		modify_node->right = NULL;
	free(erase_node);
}

static int	is_erase_list_node(t_list_node *temp)
{
	if ((cmp(temp->val, "rr\n") && cmp(temp->right->val, "rrr\n"))
		|| (cmp(temp->val, "rrr\n") && cmp(temp->right->val, "rr\n"))
		|| (cmp(temp->val, "pa\n") && cmp(temp->right->val, "pb\n"))
		|| (cmp(temp->val, "pb\n") && cmp(temp->right->val, "pa\n"))
		|| (cmp(temp->val, "ra\n" ) && cmp(temp->right->val, "rra\n"))
		|| (cmp(temp->val, "rra\n") && cmp(temp->right->val, "ra\n"))
		|| (cmp(temp->val, "rb\n" ) && cmp(temp->right->val, "rrb\n"))
		|| (cmp(temp->val, "rrb\n") && cmp(temp->right->val, "rb\n"))
		|| (cmp(temp->val, "sa\n") && cmp(temp->right->val, "sa\n"))
		|| (cmp(temp->val, "sb\n" ) && cmp(temp->right->val, "sb\n")))
		return (1);
	return (0);
}

static int	is_zip_list_node(t_list_node *temp)
{
	if ((cmp(temp->val, "ra\n") && cmp(temp->right->val, "rb\n"))
		|| (cmp(temp->val, "rb\n") && cmp(temp->right->val, "ra\n"))
		|| (cmp(temp->val, "rra\n") && cmp(temp->right->val, "rrb\n"))
		|| (cmp(temp->val, "rrb\n") && cmp(temp->right->val, "rra\n"))
		|| (cmp(temp->val, "sa\n") && cmp(temp->right->val, "sb\n"))
		|| (cmp(temp->val, "sb\n") && cmp(temp->right->val, "sa\n")))
		return (1);
	return (0);
}

void	optimize_list(t_list *list)
{
	t_list_node	*temp;

	temp = list->head->right;
	while (temp->right != NULL)
	{
		if (is_erase_list_node(temp))
		{
			temp = temp->left;
			erase_list_node(temp->right);
			if (temp == list->head)
				temp = temp->right;
		}
		else if (is_zip_list_node(temp))
		{
			temp = temp->left;
			zip_list_node(temp->right);
			if (temp == list->head)
				temp = temp->right;
		}
		else
			temp = temp->right;
	}
}
