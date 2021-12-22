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
void	better_rotate(int *arr, int ac, int target);
int		get_next_min(int *arr, int ac);


#endif
