/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:40:58 by majjig            #+#    #+#             */
/*   Updated: 2021/12/31 01:16:28 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c <= '9' && c >= '0');
}

void	ft_check_double(int *a, int ac)
{
	int	i;
	int	j;

	j = 0;
	while (j < ac)
	{
		i = j + 1;
		while (i < ac)
		{
			if (a[j] == a[i])
			{
				write(2, "ERROR\n", 6);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;
	int	tmp;

	sign = 1;
	i = 0;
	nb = 0;
	tmp = 0;
	if (str[i] == '-')
		sign = ++i * -1;
	else if (str[i] == '+')
		i++;
	while (is_digit(str[i]))
	{
		if (nb == 214748364 && str[i] == '8' && sign == -1)
			return (-2147483648);
		nb = (str[i] - '0') + (nb * 10);
		i++;
		if (nb < tmp)
			exit(write(2, "ERROR\n", 6));
		tmp = nb;
	}
	return (nb * sign);
}

void	ft_assign(int ac, int *a, char **av)
{
	int	i;
	int	j;
	int	x;

	j = 0;
	x = 0;
	while (++j && x < ac)
	{
		i = 0;
		while (av[j][i])
		{
			while (av[j][i] == ' ' || av[j][i] == '+')
				i++;
			if (is_digit(av[j][i]) || av[j][i] == '-' || av[j][i] == '+')
				a[x++] = ft_atoi(&av[j][i]);
			if (av[j][i] == '-' || av[j][i] == '+')
				i++;
			while (is_digit(av[j][i]))
				i++;
			while (av[j][i] == ' ' || av[j][i] == '\t')
				i++;
		}
	}
	ft_check_double(a, ac);
}

int	ft_count_nums(int ac, char **av)
{
	static int	i = 0;
	static int	j = 0;
	int			count;

	count = 0;
	while (++j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (is_digit(av[j][i]))
				count++;
			else if (av[j][i] != ' ' && av[j][i] != '\t')
				exit(write(2, "ERROR\n", 6));
			while (is_digit(av[j][i]))
				i++;
			if (av[j][i] && av[j][i] != ' ' && av[j][i] != '\t')
				exit(write(2, "ERROR\n", 6));
			while (av[j][i] == ' ' || av[j][i] == '\t')
				i++;
		}
	}
	return (count);
}
