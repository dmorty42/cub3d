/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:25:20 by bprovolo          #+#    #+#             */
/*   Updated: 2022/01/25 21:45:22 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	st_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*value_line(char *cmap, size_t l)
{
	char	*line;
	size_t	i;

	line = (char *)malloc(sizeof(char) * (l + 1));
	if (!line)
		return (NULL);
	line[l] = '\0';
	line[0] = ' ';
	i = 0;
	while (i < st_strlen(cmap))
	{
		line[i + 1] = cmap[i];
		i++;
	}
	while (++i < l)
		line[i] = ' ';
	return (line);
}

static char	*empty_line(size_t l)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (l + 1));
	if (!line)
		return (NULL);
	line[l] = '\0';
	line = ft_memset(line, ' ', l);
	return (line);
}

static size_t	max_line(t_list *tmap)
{
	size_t	max;
	size_t	tmp;

	max = ft_strlen((char *)tmap->content);
	while (tmap)
	{
		tmp = ft_strlen((char *)tmap->content);
		if (tmp > max)
			max = tmp;
		tmap = tmap->next;
	}
	return (max);
}

int	double_map( t_list *tmap, size_t size, char **cmap)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = max_line(tmap);
	while (i < size)
	{
		if (size == i + 1 || i == 0)
			cmap[i] = empty_line(l + 2);
		else
		{
			cmap[i] = value_line((char *)tmap->content, l + 2);
			tmap =tmap->next;
		}
		if (!cmap[i])
			return (-1);
		i++;
	}
	return (0);
}