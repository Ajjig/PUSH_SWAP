#include "push_swap.h"

void	sort5_rotate(int *arr, int ac, int max)
{
	int	i;

	i = 0;
	while (arr[i] != max)
		i++;
	if (i == 0)
		return ;
	if (i < (ac / 2))
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

void	sort3(int *a)
{
	int	first;
	int	mid;
	int	last;

	first = a[0];
	mid = a[1];
	last = a[2];
	if (last > first && last > mid && first > mid)
		write(1, "sa\n", 3);
	else if (first > mid && mid > last)
		write(1, "sa\nrra\n", 7);
	else if (last < first && last > mid && first > mid)
		write(1, "ra\n", 3);
	else if (mid > first && mid > last && last > first)
		write(1, "sa\nra\n", 6);
	else if (mid > first && mid > last && last < first)
		write(1, "rra\n", 4);
}

void	sort5(int *a, int ac)
{
	int	i;
	int	min;
	int	tmp;

	i = 0;
	tmp = ac;
	if (ac == 3)
	{
		sort3(a);
		return ;
	}
	while (ac != 3)
	{
		min = get_min(a + i, ac);
		sort5_rotate(a + i, ac, min);
		if (a[i] == get_min(a + i, ac))
		{
			write(1, "pb\n", 3);
			ac--;
			i++;
		}
	}
	sort3(a + i);
	while (tmp-- > ac)
		write(1, "pa\n", 3);
}
