#include "push_swap.h"

void	better_rotate(int *arr, int ac, int target)
{
	int	i;

	i = 0;
	while (arr[i] != target)
		i++;
	if (i == 0)
		return ;
	if (i < ac / 2 + 1)
	{
		write(1, "ra\n", 3);
		rotate(arr, ac);
	}

	else
	{
		write(1, "rra\n", 4);
		reverse_rotate(arr, ac);
	}
}

bool	is_sorted(int *arr, int ac)
{
	int	i;

	i = 1;
	while (--ac)
	{
		if (arr[i] < arr[i - 1])
			return(false);
		i++;
	}
	return(true);
}

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

int	get_next_min(int *arr, int ac)
{
	int	tmp;
	int	i;
	int	min;

	min = get_min(arr, ac);
	i = 0;
	tmp = *arr;
	if (tmp == min)
		tmp = arr[1];
	while (ac--)
	{
		if (tmp > arr[i] && arr[i] != min)
			tmp = arr[i];
		i++;
	}
	return (tmp);
}

void	push_to_b(int *a, int *b, int ac)
{
	int			min;
	static int	i = 0;
	static int	bc = 0;
	int			next_min;
	int			max;
	int			x = 0;
	while (ac)
	{
		min = get_min(a + i, ac);
		next_min = get_next_min(a + i, ac);
		max = get_max(a + i, ac);
		better_rotate(a + i, ac, min);
		if ((a[i] == min || a[i] == next_min))
		{
			b[bc++] = a[i++];
			ac--;
			write(1, "pb\n", 3);
			if (a[i - 1] == min)
				continue ;
			while (a[i] != min)
				better_rotate(a + i, ac, min);
			b[bc++] = a[i++];
			write(1, "pb\nsb\n", 6);
			ac--;
		}
		else if (a[i] == max)
		{
			b[bc++] = a[i++];
			ac--;x++;
			write(1, "pb\nrb\n", 6);
		}
	}
	while(x--)
		write(1, "rrb\n", 4);
	while (i-- > 0)
		write(1, "pa\n", 3);
}

int	main(int ac, char **av)
{
	int *a;
	int *b;

	int i = 0;
	int bc;

	a = (int *) malloc((--ac) * sizeof(int));
	b = (int *) malloc((ac) * sizeof(int));
	while (++i <= ac)
		a[i - 1] = atoi(av[i]);

	push_to_b(a, b, ac);
	i = 0;
	//while (i <= bc)
	//	printf("%d ", tmp_b[i++]);
	free(a);
	free(b);
}
