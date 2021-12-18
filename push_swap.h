#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

void	swap(int *arr, int ac);
void	rotate(int *arr, int ac);
void	reverse_rotate(int *arr, int ac);

typedef struct s_a
{
	int			nb;
	struct s_a	*next;
}				t_a;

typedef struct s_b
{
	int			nb;
	struct s_b	*next;
}				t_b;

#endif
