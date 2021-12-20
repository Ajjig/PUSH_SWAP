#include "push_swap.h"

void	better_rotate(int *arr, int ac, int target)
{
	int	i;

	i = 0;
	while (arr[i] != target)
		i++;
	if (i < ac / 2)
	{
		rotate(arr, ac);
		write(1, "ra\n", 3);
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
	int	min;
	int i = 0;
	int bc = 0;
	int next_min;

	while (!is_sorted(a + i, ac))
	{
		min = get_min(a + i, ac);
		next_min = get_next_min(a + i, ac);
		while (a[i] != min)
		{
			better_rotate(a + i, ac, min);
			if (a[i] == next_min)
			{
				b[bc++] = a[i++];
				ac--;
				write(1, "pb\n", 3);
			}
		}
		b[bc++] = a[i++];
		write(1, "pb\n", 3);
		if (bc > 1 && b[bc - 2] > b[bc - 1])
		{
			swap(b, bc - 2);
			write(1, "sb\n", 3);
		}
		ac--;
	}
	while (i > 0)
	{
		write(1, "pa\n", 3);
		a[--i] = b[--bc];
	}
}

int	main(int ac, char **av)
{
	int *a;
	int *b;
	int i = 0;

	a = (int *) malloc((--ac) * sizeof(int));
	b = (int *) malloc((ac) * sizeof(int));
	while (++i <= ac)
		a[i - 1] = atoi(av[i]);
	i = 0;
	//rotate(a, ac);
	push_to_b(a, b, ac);
	//while (i < ac)
	//	printf("%d ", a[i++]);
	free(a);
	free(b);
}
