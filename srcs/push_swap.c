/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 23:34:19 by wvenita           #+#    #+#             */
/*   Updated: 2021/06/18 22:44:11 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		sort_3(stacks);
	else if (stacks->count_a <= 5)
		sort_5(stacks);
	else
		sort_all(stacks);
}

int				main(int ac, char **av)
{
	t_data		*new;
	t_stacks	*stacks;

	if (ac < 2)
		exit(1);
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		exit(1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	ft_null(stacks, new);
	if (check_valid(ac, av))
	{
		arr_separation(ac, av, new);
		dup_check(new, stacks);
		if (is_sorted(new))
		{
			init_stack(new, stacks);
			ft_sort(stacks);
			free_stack_all(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
