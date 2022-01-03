/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:09:27 by majjig            #+#    #+#             */
/*   Updated: 2022/01/03 03:54:35 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
