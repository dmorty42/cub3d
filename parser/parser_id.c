/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:40:06 by bprovolo          #+#    #+#             */
/*   Updated: 2022/01/27 20:14:00 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	one_identif(t_node *data, char *line)
{
	char	**l_sp;
	int		readtxt;

	l_sp = ft_split(line, ' ');
	if (!l_sp)
		return (-1);
	readtxt = all_identif(data, l_sp);
	free_str_arr(l_sp);
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
			readtxt = get_one_id(data, line);
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
		readtxt = get_one_id(data, line);
	free(line);
	return (readtxt);
}

int	parser_identif(t_node *data, char *id)
{
	int	fd_map;
	int readtxt;

	// if (/* condition */)
	// {
	// 	/* code */
	// }
	fd_map = open(id, O_RDONLY);
	readtxt = text_read(data, fd_map);
	
}