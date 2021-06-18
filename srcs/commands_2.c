/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:43:33 by wvenita           #+#    #+#             */
/*   Updated: 2021/06/18 22:46:17 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int i)
{
	int		buff;

	if (a == NULL || a->next == NULL)
		return ;
	buff = a->data;
	a->data = a->next->data;
	a->next->data = buff;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int i)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->data;
	b->data = b->next->data;
	b->next->data = buff;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *s, int i)
{
	sa(s->a, 0);
	sb(s->b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	pa(t_stacks *s, int i)
{
	t_stack	*buff;

	if (s->b == NULL)
		return ;
	s->count_a += 1;
	s->count_b -= 1;
	buff = s->b;
	s->b = s->b->next;
	buff->next = s->a;
	s->a = buff;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *s, int i)
{
	t_stack	*buff;

	if (s->a == NULL)
		return ;
	s->count_a -= 1;
	s->count_b += 1;
	buff = s->a;
	s->a = s->a->next;
	buff->next = s->b;
	s->b = buff;
	if (i == 1)
		write(1, "pb\n", 3);
}
