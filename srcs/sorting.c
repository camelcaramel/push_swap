/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:59:31 by wvenita           #+#    #+#             */
/*   Updated: 2021/06/18 22:46:17 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_steps_markup(t_stack *b, int count)
{
	int		i;
	int		iter;
	t_stack	*buff;

	i = -1;
	iter = count / 2;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

static void	ft_minimum_insertion_steps(t_stacks *stacks, t_steps *steps)
{
	int		min_action;
	t_stack	*first_a;
	t_stack	*first_b;

	min_action = -1;
	first_a = stacks->a;
	first_b = stacks->b;
	while (stacks->b)
	{
		min_action = find_position(stacks, stacks->b, steps, min_action);
		stacks->a = first_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = first_b;
}

static void	ft_instruction_execution(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ra(&stacks->a, 1);
		else
			rra(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			rb(&stacks->b, 1);
		else
			rrb(&stacks->b, 1);
		steps->count_b--;
	}
	pa(stacks, 1);
}

static void	ft_start_sort(t_stacks *stacks)
{
	t_steps *step;

	if (!(step = (t_steps *)malloc(sizeof(t_steps))))
		exit(1);
	while (stacks->count_b != 0)
	{
		step->count_a = -1;
		step->count_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		ft_steps_markup(stacks->a, stacks->count_a);
		ft_steps_markup(stacks->b, stacks->count_b);
		ft_minimum_insertion_steps(stacks, step);
		ft_instruction_execution(stacks, step);
	}
	if ((count2min(stacks->a, stacks->min)) > stacks->count_a / 2)
	{
		while (stacks->a->data != stacks->min)
			rra(&stacks->a, 1);
	}
	else
		while (stacks->a->data != stacks->min)
			ra(&stacks->a, 1);
	free(step);
}

void		sort_all(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max)
		{
			pb(stacks, 1);
			if (stacks->b->data > stacks->med)
				rb(&stacks->b, 1);
		}
		else
			ra(&stacks->a, 1);
	}
	if (stacks->a->data < stacks->a->next->data)
		sa(stacks->a, 1);
	pa(stacks, 1);
	ft_start_sort(stacks);
}
