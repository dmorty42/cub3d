/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:24:33 by bprovolo          #+#    #+#             */
/*   Updated: 2022/01/24 22:08:17 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	player_search(t_node *data)
{
	int	i;
	int j;
	char **map;
	
	map = data->map.map;
	data->map.w = ft_strlen(map[0]);
	i = 0;
	while (map[i])
		i++;
	data->map.h = i;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map [i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->plr->x = j;
				data->plr->y = i;
			}
		}
	}
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

size_t	map_meter(t_list *map)
{
	size_t	size;

	size = 0;
	while (map)
	{
		if (ft_strcmp((char *)map->content, "") != 0)
			size++;
		map = map->next;
	}
	return (size);
}



static int map_writer(t_node *data, t_list *map)
{
	size_t	size = 0;
	
	// if (mapcheck(map))
		// return ()
	size = map_meter(map);
	data->map.map = (char **)malloc(sizeof(char *) * (size + 3));
	// if (!data->map.map)
		// return
	data->map.map[size + 2] = NULL;
	// if (map_copy)
	player_search(data);
	return (0);
}

static	int	list_line(t_list **map, char *line)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (!new)
		return (1);
	ft_lstadd_back(map, new);
	return (0);
}

static t_list	*map_reader(int fd_map, char *line)
{
	t_list	*map;
	char	*l;
	int		readtxt;
	int		rtext;
	
	map = NULL;
	rtext = 1;
	if (list_line(&map, line))
		rtext = -1;
	readtxt = get_next_line(fd_map, &l);
	while (0 < readtxt && 0 < rtext)
	{
		if (list_line(&map, l))
			rtext = -1;
		if (0 < rtext)
			readtxt = get_next_line(fd_map, &l);
	}
	// if (readtxt == -1 || rtext == -1)
		// return(clean)
	rtext = list_line(&map, l);
	// if (rtext)
		// return (clean)
	return (map);
	
}

int	parse_map(t_node *data, char *av)
{
	t_list	*map;
	char	*line;
	int		fd_map;
	int		readtxt;

	fd_map = open(av, O_RDONLY);
	readtxt = get_next_line(fd_map, &line);
	while (0 < readtxt) // !is_map_started
	{
		free(line);
		readtxt = get_next_line(fd_map, &line);
	}
	// if (readtxt == -1 || !readtxt)
	// {
	// 	free(line);
	// 	return (1);
	// }
	printf("tesst )))))))) ((((((((( |||||||||\n");
	map = map_reader(fd_map, line);
	close(fd_map);
	if (!map)
		return (1);
	readtxt = map_writer(data, map);
	ft_lstclear(&map, free);
	return (readtxt); 	
}