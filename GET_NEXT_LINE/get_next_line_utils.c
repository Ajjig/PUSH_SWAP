/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:38:28 by majjig            #+#    #+#             */
/*   Updated: 2022/01/03 21:00:36 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*str++)
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		total;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return (s1);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc(total * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	free(s2);
	return (str);
}

int	is_nl(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
