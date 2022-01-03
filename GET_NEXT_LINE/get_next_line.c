/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:38:11 by majjig            #+#    #+#             */
/*   Updated: 2022/01/03 21:00:18 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*new_remain(char *line, char *remain)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (is_nl(line) == 0)
	{
		free(remain);
		return (NULL);
	}
	while (line[j])
	{
		if (line[j++] == '\n')
			break ;
	}
	if (line[j] == 0)
	{
		free(remain);
		return (0);
	}
	new = ft_strdup(line + j);
	free(remain);
	return (new);
}

char	*new_line(char *line)
{
	int		len;
	int		i;
	char	*new;

	len = 0;
	i = 0;
	if (is_nl(line) == 0)
		return (line);
	while (line[len] != '\n')
		len++;
	len++;
	new = (char *) malloc(len + 1);
	len = 0;
	while (line[len] != '\n')
		new[i++] = line[len++];
	new[i++] = '\n';
	new[i] = 0;
	free(line);
	return (new);
}

char	*read_file(int fd, int *end)
{
	char	*readed;
	int		nb;
	char	*tmp;

	readed = (char *) malloc(BUFFER_SIZE + 1);
	nb = read(fd, readed, BUFFER_SIZE);
	if (nb <= 0)
	{
		*end = 10;
		free(readed);
		return (NULL);
	}
	if (nb < BUFFER_SIZE)
	{
		readed[nb] = 0;
		tmp = ft_strdup(readed);
		free(readed);
		return (tmp);
	}
	readed[BUFFER_SIZE] = 0;
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*remain = NULL;
	char		*line;
	int			end;

	end = 0;
	if (fd < 0)
		return (NULL);
	if (remain)
		line = ft_strdup(remain);
	else
		line = read_file(fd, &end);
	while (fd >= 0)
	{
		if (is_nl(line) || end)
		{
			remain = new_remain(line, remain);
			return (new_line(line));
		}
		line = ft_strjoin(line, read_file(fd, &end));
	}
	return (NULL);
}
