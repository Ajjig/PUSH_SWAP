/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:46:17 by majjig            #+#    #+#             */
/*   Updated: 2021/12/31 00:48:49 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int *arr, int ac)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = *arr;
	while (ac--)
	{
		if (tmp > arr[i])
			tmp = arr[i];
		i++;
	}
	return (tmp);
}

int	get_max(int *arr, int ac)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = *arr;
	while (ac--)
	{
		if (tmp < arr[i])
			tmp = arr[i];
		i++;
	}
	return (tmp);
}

int	get_next_max(int *arr, int ac)
{
	int	tmp;
	int	i;
	int	max;

	max = get_max(arr, ac);
	i = 0;
	tmp = *arr;
	if (tmp == max)
		tmp = arr[1];
	while (ac--)
	{
		if (tmp < arr[i] && arr[i] != max)
			tmp = arr[i];
		i++;
	}
	return (tmp);
}
