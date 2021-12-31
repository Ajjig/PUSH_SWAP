/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:43:05 by majjig            #+#    #+#             */
/*   Updated: 2021/12/31 00:54:53 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_here(int *a, int ac, int pivot)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (a[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}

int	calc(int *a, int pivot, int ac)
{
	int	i;
	int	less;

	less = 0;
	i = 0;
	while (i < ac)
	{
		if (a[i] < pivot)
			less++;
		i++;
	}
	if (less == ac / 3)
		return (1);
	return (0);
}

int	get_pivot(int *a, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (calc(a, a[i], ac))
			return (a[i]);
		i++;
	}
	return (0);
}
