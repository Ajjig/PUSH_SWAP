/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:09:35 by majjig            #+#    #+#             */
/*   Updated: 2022/01/03 03:29:11 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*next_inst(char *all)
{
	int			i;
	static char	inst[4];

	i = 0;
	while (all[i] && all[i] != '\n')
	{
		inst[i] = all[i];
		i++;
	}
	inst[i] = 0;
	return (inst);
}

void	is_valid(char *instraction)
{
	int			i;
	static char	*all[11] = {"sa\n", "ra\n", "rra\n", "pa\n", "sb\n",
		"rb\n", "rrb\n", "pb\n", "rrr\n", "ss\n", "rr\n"};

	i = 0;
	if ((ft_strlen(instraction) == 3 || ft_strlen(instraction) == 4))
		while (i < 11)
			if (ft_strcmp(instraction, all[i++]))
				return ;
	write(2, "ERROR\n", 6);
	exit(1);
}

void	rev_rotate(int *arr, int ac)
{
	int	i;
	int	tmp;

	tmp = arr[ac - 1];
	i = ac;
	while (--i)
	{
		arr[i] = arr[i - 1];
	}
	arr[i] = tmp;
}

void	ft_handler(char *all, int *a, int *b, int ac)
{
	static int	i = 0;
	char		*inst;
	int			bc;

	bc = ac;
	while (*all)
	{
		inst = next_inst(all);
		if ((ft_strcmp(inst, "ra") || ft_strcmp(inst, "rr")) && i < ac - 1)
			rotate(a + i, ac - i);
		if ((ft_strcmp(inst, "rra") || ft_strcmp(inst, "rrr")) && i < ac - 1)
			reverse_rotate(a + i, ac - i);
		if ((ft_strcmp(inst, "sa") || ft_strcmp(inst, "ss")) && i < ac - 1)
			swap(a + i, 0);
		if (ft_strcmp(inst, "pa") && bc < ac)
			a[--i] = b[bc++];
		if (ft_strcmp(inst, "pb") && i < ac)
			b[--bc] = a[i++];
		if ((ft_strcmp(inst, "rb") || ft_strcmp(inst, "rr")) && bc < ac - 1)
			rotate(b + bc, ac - bc);
		if ((ft_strcmp(inst, "sb") || ft_strcmp(inst, "ss")) && bc < ac - 1)
			swap(b + bc, 0);
		if ((ft_strcmp(inst, "rrb") || ft_strcmp(inst, "rrr")) && bc < ac - 1)
			reverse_rotate(b + bc, ac - bc);
		all += ft_strlen(inst) + 1;
	}
}

int	main(int ac, char **av)
{
	char	*all;
	char	*instraction;
	int		*a;
	int		*b;

	all = (char *) malloc(1);
	*all = 0;
	ac = ft_count_nums(ac, av);
	a = (int *) malloc((ac) * sizeof(int));
	b = (int *) malloc((ac) * sizeof(int));
	ft_assign(ac, a, av);
	while (1)
	{
		instraction = get_next_line(0);
		if (instraction == NULL)
			break ;
		is_valid(instraction);
		all = ft_strjoin(all, instraction);
	}
	ft_handler(all, a, b, ac);
	if (is_sorted(a, ac))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(all);
	free(a);
	free(b);
}
