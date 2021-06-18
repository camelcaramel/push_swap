/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:14:55 by donghwik          #+#    #+#             */
/*   Updated: 2021/06/18 22:14:55 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct		s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct		s_data
{
	int				a[10000];
	int				count_element;
}					t_data;

typedef struct		s_stack
{
	int				data;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	int				count_a;
	int				count_b;
	int				min;
	int				max;
	int				med;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

int					is_all_space(const char *str);
int					is_sorted(t_data *new);
int					check_valid(int ac, char **av);
void				dup_check(t_data *new, t_stacks *stacks);
void				arr_separation(int ac, char **av, t_data *new);
void				stack_up(t_data *new, int *buff, int count);
void				init_stack(t_data *new, t_stacks *stacks);
void				free_stack_all(t_stacks *stacks);
void				ft_null(t_stacks *stacks, t_data *new);
void				sort_3(t_stacks *stacks);
void				sort_5(t_stacks *stacks);
void				quick_sort(int *array, int start, int end);
int					partition(int *array, int start, int end);
void				sort_all(t_stacks *stacks);
int					find_position(t_stacks *s, t_stack *b,
							t_steps *steps, int min);
int					count2min(t_stack *a, int min);

void				ra(t_stack **a, int i);
void				rb(t_stack **b, int i);
void				rr(t_stacks *s, int i);
void				rra(t_stack **a, int i);
void				rrb(t_stack **b, int i);
void				sa(t_stack *a, int i);
void				sb(t_stack *a, int i);
void				ss(t_stacks *s, int i);
void				pa(t_stacks *s, int i);
void				pb(t_stacks *s, int i);
void				rrr(t_stacks *s, int i);

int					*ft_intarrcpy(int *dst, const int *src, int count);
char				**ft_strsplit(char const *s, char c);
size_t				ft_wordcount(char const *s, char c);
int					ft_atoi(const char *str);

int					ft_isdigit(int c);
int					ft_isspace(int c);
void				ft_error(void);

#endif