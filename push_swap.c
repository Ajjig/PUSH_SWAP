#include "push_swap.h"

void	better_rotate(int *arr, int ac, int min, int max, int next)
{
	int	i;
	int	j;

	i = 0;
	j = ac;
	while (arr[i] != min && arr[i] != max && arr[i] != next)
		i++;
	while (arr[j] != min && arr[j] != max && arr[j] != next)
		j--;
	if (i == 0)
		return ;
	if (i < (ac - j))
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
	while (ac--)
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
	static int	i = 0;
	static int	bc = 0;
	int			x = 0;
	t_target	target;
	while (ac)
	{
		target.min = get_min(a + i, ac);
		target.next = get_next_min(a + i, ac);
		target.max = get_max(a + i, ac);
		better_rotate(a + i, ac, target.min, target.max, target.next);

		if ((a[i] == target.min || a[i] == target.next))
		{
			b[bc++] = a[i++];
			ac--;
			write(1, "pb\n", 3);
			if (a[i - 1] == target.min)
				continue ;
			while (a[i] != target.min)
			{
				if (a[i] == target.max)
				{
					b[bc++] = a[i++];
					ac--;x++;
					write(1, "pb\nrb\n", 6);
				}
				better_rotate(a + i, ac, target.min, target.max, target.min);
			}
			b[bc++] = a[i++];
			write(1, "pb\nsb\n", 6);
			ac--;
		}
		else if (a[i] == target.max)
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
