/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:38:52 by majjig            #+#    #+#             */
/*   Updated: 2022/01/02 20:55:04 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 1024

/* PROTOTYPES */
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		is_nl(char *s);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*new_line(char *line);
char	*new_remain(char *line, char *remain);
char	*read_file(int fd, int *end);
#endif
