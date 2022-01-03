/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:09:53 by majjig            #+#    #+#             */
/*   Updated: 2022/01/03 02:31:59 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

void	swap(int *arr, int ac);
void	rotate(int *arr, int ac);
void	reverse_rotate(int *arr, int ac);
int		get_min(int *arr, int ac);
int		is_sorted(int *arr, int ac);
int		get_next_max(int *arr, int ac);
void	better_rotate(int *arr, int ac, int max);
void	sort5(int *a, int ac);
void	sort3(int *a);
void	sort5_rotate(int *arr, int ac, int max);
int		ft_count_nums(int ac, char **av);
void	ft_assign(int ac, int *a, char **av);
int		get_pivot(int *a, int ac);
int		calc(int *a, int pivot, int ac);
int		is_here(int *a, int ac, int pivot);
int		get_max(int *arr, int ac);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		is_nl(char *s);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*new_line(char *line);
char	*new_remain(char *line, char *remain);
char	*read_file(int fd, int *end);
int		ft_count_nums(int ac, char **av);
void	ft_assign(int ac, int *a, char **av);
int		ft_strcmp(char *s1, char *s2);
void	push_to_b(int *a, int *b, int ac);
void	push_to_a(int *a, int bc);

typedef struct s_target
{
	int	max;
	int	next;
	int	min;
}	t_target;

#endif
