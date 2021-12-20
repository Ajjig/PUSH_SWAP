#include "push_swap.h"

void	swap(int *arr, int ac)
{
	int tmp;

	tmp = arr[ac];
	arr[ac] = arr[ac + 1];
	arr[ac + 1] = tmp;
}

void	rotate(int *arr, int ac)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arr[i];
	while (++i < ac)
	{
		arr[i - 1] = arr[i];
	}
	arr[i - 1] = tmp;
}

void	reverse_rotate(int *arr, int ac)
{
	int	i;
	int	tmp;

	tmp = arr[ac - 1];
	i = ac;
	while (--i)
	{
		arr[i] = arr[i - 1];
	}
	arr[i] = tmp;
}
