#include "push_swap.h"

bool	is_sorted(int *arr, int ac)
{
	int	i;

	i = 1;
	while (--ac)
	{
		if (arr[i] < arr[i - 1] && arr[i - 1] != 0)
			return(false);
		i++;
	}
	return(true);
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

void	push_to_b(int *a, int *b, int ac)
{
	int	max;
	int i = 0;
	int bc = 0;

	while (!is_sorted(a, ac))
	{
		max = get_max(a + i, ac);
		while (a[i] != max)
		{
			rotate(a + i, ac);
			write(1, "ra\n", 3);
		}
		b[bc++] = a[i];
		write(1, "pb\n", 3);
		ac--;
		i++;
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
