/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:15:50 by bprovolo          #+#    #+#             */
/*   Updated: 2022/01/25 22:38:43 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	checker_char(char c)
{
	int				i;

	i = -1;
	while (++i < 7)
		if (c == ' ' || c == '0'
			|| c == '1' || c == 'N'
			|| c == 'S' || c == 'E'
			|| c == 'W')
			return (0);
	return (-1);
}

int	checker_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (-1);
	return (0);
}

static int	player_checker(t_list *tmap)
{
	int			i;
	char		*line;
	int			players;

	players = 0;
	while (tmap)
	{
		i = -1;
		line = (char *)tmap->content;
		while (line[++i])
		{
			if (checker_char(line[i]) == -1)
				return (-1);
			if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E')
				players++;
		}
		tmap = tmap->next;
	}
	if (players != 1)
		return (-1);
	return (0);
}

int	map_checker(t_list *tmap)
{
	t_list	*tmp;

	tmp = tmap;
	if (player_checker(tmap) == -1)
		return (-1);
	while (tmp && ft_strcmp((char *)tmp->content, "") != 0)
	{
		if (checker_spaces((char *)tmp->content) == -1)
			return (-1);
		tmp = tmp->next;
	}
	while (tmp && !ft_strcmp((char *)tmp->content, ""))
		tmp = tmp->next;
	if (tmp)
		return (-1);
	return (0);
}
