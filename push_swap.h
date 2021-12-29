#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

void	swap(int *arr, int ac);
void	rotate(int *arr, int ac);
void	reverse_rotate(int *arr, int ac);
int		get_min(int *arr, int ac);
bool	is_sorted(int *arr, int ac);
int		get_next_min(int *arr, int ac);
void	better_rotate(int *arr, int ac, int max);
void	sort5(int *a, int ac);
void	sort3(int *a);
void	sort5_rotate(int *arr, int ac, int max);

typedef struct s_target
{
	int max;
	int next;
	int min;
}	t_target;
typedef struct s_counts
{
	int ac;
	int rra_credit;
	int i;
	int bc;
} t_counts;

#endif
