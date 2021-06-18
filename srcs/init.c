/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:35:15 by wvenita           #+#    #+#             */
/*   Updated: 2021/06/18 22:43:00 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_create_stack(const int *buff, int count)
{
	int			i;
	t_stack		*new_list;
	t_stack		*first_element;

	i = 0;
	if (!(new_list = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	first_element = new_list;
	while (i < count)
	{
		if (i < count - 1)
		{
			if (!(new_list->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(1);
		}
		new_list->data = buff[i];
		if (i == (count - 1))
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	return (first_element);
}

void			init_stack(t_data *new, t_stacks *stacks)
{
	stacks->a = ft_create_stack(new->a, new->count_element);
	stacks->b = NULL;
}

void			free_stack_all(t_stacks *stacks)
{
	int			i;
	t_stack		*buff;

	i = 0;
	while (i < stacks->count_a)
	{
		buff = stacks->a;
		stacks->a = stacks->a->next;
		free(buff);
		i++;
	}
	i = 0;
	while (i < stacks->count_b)
	{
		buff = stacks->b;
		stacks->b = stacks->b->next;
		free(buff);
		i++;
	}
}

void			ft_null(t_stacks *stacks, t_data *new)
{
	new->count_element = 0;
	stacks->count_a = 0;
	stacks->count_b = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->med = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}
