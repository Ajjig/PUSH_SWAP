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

typedef struct s_target
{
	int min;
	int max;
	int next;
}	t_target;
typedef struct s_counts
{
	int ac;
	int rra_credit;
	int i;
	int bc;
} t_counts;

#endif
