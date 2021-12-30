#include "push_swap.h"

int	is_digit(char c)
{
	return (c <= '9' && c >= '0');
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
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (is_digit(str[i]))
	{
		nb = (str[i] - '0') + (nb * 10);
		i++;
		if (nb < tmp)
		{
			write(2, "ERROR\n", 6);
			exit(1);
		}
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
	while(++j && x < ac)
	{
		i = 0;
		while (av[j][i])
		{
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
}

int	ft_count_nums(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while(++j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (is_digit(av[j][i]))
				count++;
			while (is_digit(av[j][i]))
				i++;
			if (av[j][i] && av[j][i] != ' ' && av[j][i] != '\t')
			{
				write(2, "ERROR\n", 6);
				exit(1);
			}
			while (av[j][i] == ' ' || av[j][i] == '\t')
				i++;
		}
	}
	return (count);
}

