/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:43:19 by wvenita           #+#    #+#             */
/*   Updated: 2021/06/18 22:44:27 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_search_duplicate(const int *dup, int count)
{
	int		i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}

static void	ft_number_availability(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

static void	ft_valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

void		dup_check(t_data *new, t_stacks *stacks)
{
	int		*dup;

	if (!(dup = (int *)malloc(sizeof(int) * (new->count_element))))
		exit(1);
	dup = ft_intarrcpy(dup, new->a, new->count_element);
	quick_sort(dup, 0, new->count_element - 1);
	ft_search_duplicate(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}

int			check_valid(int ac, char **av)
{
	int		i;
	int		ret;

	ret = 0;
	i = 1;
	while (i < ac)
	{
		if (is_all_space(av[i]))
		{
			ft_number_availability(av[i]);
			ft_valid_str(av[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}
