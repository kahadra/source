/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:42:04 by seunpark          #+#    #+#             */
/*   Updated: 2022/02/05 21:16:07 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define S_A 1
# define S_B 2

typedef struct s_stack_node
{
	int				val;
	struct s_stack_node	*up;
	struct s_stack_node	*down;
}	t_stack_node;

typedef struct s_stack
{
	struct s_stack_node	*top;
	struct s_stack_node	*bottom;
}	t_stack;

typedef struct s_list_node
{
	char				*val;
	struct s_list_node	*left;
	struct s_list_node	*right;
}	t_list_node;

typedef struct s_list
{
	struct s_list_node	*head;
}	t_list;

typedef struct	s_var
{
	int				max_size;
	int				*piv_arr;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	struct s_list	*list;
	int				a_size;
	int				b_size;
}	t_var;

/* preprocess */
void		preprocess(t_var *var, int argc, char **argv);

/* re_a, re_b */
void		re_a(t_var *var, int pre_size, int pre_piv_idx);
void		re_b(t_var *var, int pre_size, int pre_piv_idx);

/* sort */
void		sort_four_only_a(t_var *var);
void		sort_four_only_b(t_var *var);
void		sort_four_a(t_var *var);
void		sort_four_b(t_var *var);
void		sort_three_a(t_var *var);
void		sort_three_b(t_var *var);
void		sort_three_only_a(t_var *var);
void		sort_three_only_b(t_var *var);

/* stack */
char		*sa(t_var *var);
char		*sb(t_var *var);
char		*ss(t_var *var);
char		*pa(t_var *var);
char		*pb(t_var *var);
char		*ra(t_var *var);
char		*rb(t_var *var);
char		*rr(t_var *var);
char		*rra(t_var *var);
char		*rrb(t_var *var);
char		*rrr(t_var *var);

/* util list */
t_list_node	*new_list_node(char *str);
void		init_list(t_var *var);
void		save_list(t_var *var, char *str);
void		print_list(t_var *var);
void		optimize_list(t_list *list);

/* util preprocess */
void		quick_sort(int *arr, int start, int end);
void		check_duplication(int *arr, int len);

/* util sort */
int				is_sorted(t_stack_node *temp, int len, int now_stack);
t_stack_node	*max_node(t_stack_node *temp, int len);
t_stack_node	*min_node(t_stack_node *temp, int len);

/* util stack */
t_stack_node	*new_stack_node(int num);
void	init_stack(t_var *var);
void	push_top(t_stack *stack, t_stack_node *new_node);
void	push_bottom(t_stack *stack, t_stack_node *new_node);
t_stack_node	*pop_top(t_stack *stack);
t_stack_node	*pop_bottom(t_stack *stack);
int	get_stack_size(t_stack *stack);
int	get_available_stack_size_a(int pre_size);
int	get_available_stack_size_b(int pre_size);

/* util standard */
void	ft_putstr(char *str, int fd);
void	ft_error(void);
size_t	ft_strlen(const char *str);
int		cmp(char *s1, char *s2);

#endif
