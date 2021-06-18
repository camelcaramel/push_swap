/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:32:26 by wvenita           #+#    #+#             */
/*   Updated: 2021/06/18 22:40:51 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_smaller_element_detection(t_stack *a, int buff, int src)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->data < buff && save->data > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

static void	ft_help_finding_place(t_stacks *s,
		t_stack *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->data;
		if (b->data > s->a->data)
		{
			*action += 1;
			if (b->data < s->a->next->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (ft_smaller_element_detection(s->a, *buff, b->data) == 1)
	{
		while (s->a)
		{
			if (s->a->data < *buff && s->a->data > b->data)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int			find_position(t_stacks *s, t_stack *b, t_steps *steps, int min)
{
	int		action;
	int		res;
	int		buff;

	action = 0;
	buff = 0;
	ft_help_finding_place(s, b, &action, &buff);
	if (s->a->rotate == -1)
		action = s->count_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

int			count2min(t_stack *a, int min)
{
	int		i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
