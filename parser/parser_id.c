/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:40:06 by bprovolo          #+#    #+#             */
/*   Updated: 2022/02/01 23:03:54 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	identif_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	one_identif(t_node *data, char *line)
{
	char	**l_sp;
	int		readtxt;

	l_sp = ft_split(line, ' ');
	if (!l_sp)
		return (-1);
	readtxt = all_identif(data, l_sp);
	identif_free(l_sp);
	return (readtxt);
}

int	text_read(t_node *data, int fd_map)
{
	int		readtxt;
	char	*line;

	readtxt = get_next_line(fd_map, &line);
	if (readtxt == -1)
		return (-1);
	while (one_search(line) == 0 && readtxt > 0)
	{
		if (ft_strcmp(line, "") != 0)
		{
			readtxt = one_identif(data, line);
			free(line);
			if (readtxt == -1)
				return (-1);
		}
		else
			free(line);
		readtxt = get_next_line(fd_map, &line);
	}
	if (readtxt == -1)
		return (-1);
	if (ft_strcmp(line, "") != 0 && one_search(line) == 0)
		readtxt = one_identif(data, line);
	free(line);
	return (readtxt);
}

int	parse_identif(t_node *data, char *id)
{
	int	fd_map;
	int	readtxt;

	if (checker_file(id) == -1)
		return (-1);
	fd_map = open(id, O_RDONLY);
	readtxt = text_read(data, fd_map);
	if (data->tmap.floor == -1
		|| data->tmap.ceilling == -1 || readtxt == -1)
	{
		close(fd_map);
		return (-1);
	}
	if (data->tmap.cW != 1 || data->tmap.cS != 1
		|| data->tmap.cE != 1 || data->tmap.cN != 1
		|| data->tmap.cC != 1 || data->tmap.cF != 1)
		return (-1);
	readtxt = while_gnl(fd_map);
	close(fd_map);
	if (readtxt == -1)
		return (-1);
	return (0);
}
