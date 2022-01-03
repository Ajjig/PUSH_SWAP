/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:09:47 by majjig            #+#    #+#             */
/*   Updated: 2022/01/03 02:42:18 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *arr, int ac)
{
	ac = arr[0];
	arr[0] = arr[1];
	arr[1] = ac;
}

void	rotate(int *arr, int ac)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arr[i];
	while (++i < ac)
	{
		arr[i - 1] = arr[i];
	}
	arr[i - 1] = tmp;
}

void	reverse_rotate(int *arr, int ac)
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

void	better_rotate(int *arr, int ac, int max)
{
	int	i;

	i = 0;
	while (arr[i] != max)
		i++;
	if (i == 0)
		return ;
	if (i < (ac / 2) + 1)
	{
		write(1, "rb\n", 3);
		rotate(arr, ac);
	}
	else
	{
		write(1, "rrb\n", 4);
		reverse_rotate(arr, ac);
	}
}
