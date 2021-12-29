#include "push_swap.h"

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

bool	is_sorted(int *arr, int ac)
{
	int	i;

	i = 1;
	while (ac--)
	{
		if (arr[i] < arr[i - 1])
			return(false);
		i++;
	}
	return(true);
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

int get_pivot(int *a, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (calc(a, a[i], ac))
			return (a[i]);
		i++;
	}
	return(0);
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

int is_here(int *a, int ac, int pivot)
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

void	push_to_a(int *a, int bc)
{
	static int	i = 0;
	t_target	target;
	static int	is_next = 0;
	static int	x = 0;

	while (bc > 0)
	{
		target.next = get_next_max(a + i, bc);
		target.max = get_max(a + i, bc);
		target.min = get_min(a + i, bc);
		better_rotate(a + i, bc, target.max);
		if (a[i] == target.max || (a[i] == target.next && !is_next) || a[i] == target.min)
		{
			write(1, "pa\n", 3);
			if (a[i] == target.next && is_next == 0)
				is_next = 1;
			else if (is_next && a[i] == target.max)
				write(is_next-- , "sa\n", 3);
			else if (a[i] == target.min)
				write((x++ * 0 + 1), "ra\n", 3);
			i += (bc-- * 0) + 1;
		}
	}
	while (x--)
		write(1, "rra\n", 4);
}

void	push_to_b(int *a, int *b, int ac)
{
	int	i;
	int	pivot;
	int	bc = ac;

	i = 0;
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
	int *a;
	int *b;

	int i = 0;
	int bc;

	a = (int *) malloc((--ac) * sizeof(int));
	b = (int *) malloc((ac) * sizeof(int));
	while (++i <= ac)
		a[i - 1] = atoi(av[i]);
	if (ac <= 5)
		sort5(a, ac);
	else
		push_to_b(a, b, ac);
	free(a);
	free(b);
}
