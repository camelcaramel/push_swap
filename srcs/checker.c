/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:28:44 by wvenita           #+#    #+#             */
/*   Updated: 2021/06/18 22:46:17 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_action_processing(char *line, t_stacks *s)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(s->a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(s->b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(s, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(s, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(s, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(&s->a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(&s->b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(s, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(&s->a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(&s->b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(s, 0);
	else
		ft_error();
}

static void		ft_read_action(t_stacks *s)
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_action_processing(line, s);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

static int		ft_stack_sorted(t_stacks *s)
{
	int			i;
	int			buff;
	t_stack		*save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->data;
		s->a = s->a->next;
		if (buff > s->a->data)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
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
		init_stack(new, stacks);
		ft_read_action(stacks);
		if ((ft_stack_sorted(stacks)) && stacks->count_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack_all(stacks);
	free(new);
	free(stacks);
	return (0);
}
