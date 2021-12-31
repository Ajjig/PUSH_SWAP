/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:09:42 by majjig            #+#    #+#             */
/*   Updated: 2021/12/31 01:09:43 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *arr, int ac)
{
	int	i;

	i = 1;
	while (--ac)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	push_to_a(int *a, int bc)
{
	static int	i = 0;
	t_target	tar;
	static int	is = 0;
	static int	x = 0;

	while (bc > 0)
	{
		tar.next = get_next_max(a + i, bc);
		tar.max = get_max(a + i, bc);
		tar.min = get_min(a + i, bc);
		better_rotate(a + i, bc, tar.max);
		if (a[i] == tar.max || (a[i] == tar.next && !is) || a[i] == tar.min)
		{
			write(1, "pa\n", 3);
			if (a[i] == tar.next && is == 0)
				is = 1;
			else if (is && a[i] == tar.max)
				write(is--, "sa\n", 3);
			else if (a[i] == tar.min)
				write(++x * 0 + 1, "ra\n", 3);
			i += (--bc * 0) + 1;
		}
	}
	while (x--)
		write(1, "rra\n", 4);
}

void	push_to_b(int *a, int *b, int ac)
{
	int	i;
	int	pivot;
	int	bc;

	i = 0;
	bc = ac;
	while (bc > 5)
	{
		pivot = get_pivot(a + i, bc);
		while (is_here(a + i, bc, pivot) && bc > 5)
		{
			if (a[i] < pivot)
			{
				write(1, "pb\n", 3);
				b[--bc] = a[i++];
				continue ;
			}
			rotate(a + i, bc);
			write(1, "ra\n", 3);
		}
	}
	sort5(a + i, bc);
	push_to_a(b + bc, ac - bc);
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	i;

	i = 0;
	ac = ft_count_nums(ac, av);
	a = (int *) malloc((ac) * sizeof(int));
	b = (int *) malloc((ac) * sizeof(int));
	ft_assign(ac, a, av);
	if (is_sorted(a, ac))
		ac--;
	else if (ac < 3)
	{
		if (a[0] > a[1])
			write(1, "sa\n", 3);
	}
	else if (ac <= 5)
		sort5(a, ac);
	else
		push_to_b(a, b, ac);
	free(a);
	free(b);
}
