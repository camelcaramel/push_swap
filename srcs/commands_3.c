/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:43:33 by wvenita           #+#    #+#             */
/*   Updated: 2021/06/18 22:45:04 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_all_space(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

int		is_sorted(t_data *new)
{
	int i;

	i = 0;
	while (i < (new->count_element - 1))
	{
		if (new->a[i] > new->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	rrr(t_stacks *s, int i)
{
	rra(&s->a, 0);
	rrb(&s->b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
