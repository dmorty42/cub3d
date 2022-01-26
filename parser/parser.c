/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:24:33 by bprovolo          #+#    #+#             */
/*   Updated: 2022/01/25 22:15:03 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*cleaner(t_list **head, char *str)
{
	if (head)
		ft_lstclear(head, free);
	if (str)
		free(str);
	return (NULL);
}

static void	player_search(t_node *data)
{
	int	i;
	int j;
	char **cmap;

	
	cmap = data->tmap.cmap;
	data->tmap.w = st_strlen(cmap[0]);
	i = 0;
	while (cmap[i])
		i++;
	data->tmap.h = i;
	i = -1;
	while (cmap[++i])
	{
		j = -1;
		while (cmap[i][++j])
		{
			if (cmap[i][j] == 'N' || cmap [i][j] == 'S'
				|| cmap[i][j] == 'E' || cmap[i][j] == 'W')
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

size_t	map_meter(t_list *tmap)
{
	size_t	size;

	size = 0;
	while (tmap)
	{
		if (ft_strcmp((char *)tmap->content, "") != 0)
			size++;
		tmap = tmap->next;
	}
	return (size);
}



static int map_writer(t_node *data, t_list *tmap)
{
	size_t	size = 0;
	if (map_checker(tmap) == -1)
		return (-1);
	size = map_meter(tmap);
	data->tmap.cmap = (char **)malloc(sizeof(char *) * (size + 3));
	// if (!data->map.map)
		// return
	data->tmap.cmap[size + 2] = NULL;
	if (double_map(tmap, size + 2, data->tmap.cmap) == -1)
		return (-1);
	if (check_border(data->tmap.cmap) == -1)
		return (-1);
	player_search(data);
	return (0);
}

static	int	list_line(t_list **tmap, char *line)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (!new)
		return (1);
	ft_lstadd_back(tmap, new);
	return (0);
}

static t_list	*map_reader(int fd_map, char *line)
{
	t_list	*tmap;
	char	*l;
	int		readtxt;
	int		rtext;
	
	tmap = NULL;
	rtext = 1;
	if (list_line(&tmap, line))
		rtext = -1;
	readtxt = get_next_line(fd_map, &l);
	while (0 < readtxt && 0 < rtext)
	{
		if (list_line(&tmap, l))
			rtext = -1;
		if (0 < rtext)
			readtxt = get_next_line(fd_map, &l);
	}
	if (readtxt == -1 || rtext == -1)
		return(cleaner(&tmap, l));
	rtext = list_line(&tmap, l);
	if (rtext == -1)
		return (cleaner(&tmap, l));
	return (tmap);
	
}

int	one_search(char *line)
{
	int	unit;
	int	i;
	
	unit = 0;
	i = 0;
	while ((line[i] == '1' || line[i] == ' ') && line[i])
	{
		if (line[i] == '1')
			unit = 1;
		i++;
	}
	if (unit > 0 && !line[i])
		return (1);
	return (0);
}

int	parse_map(t_node *data, char *av)
{
	t_list	*tmap;
	char	*line;
	int		fd_map;
	int		readtxt;

	fd_map = open(av, O_RDONLY);
	readtxt = get_next_line(fd_map, &line);
	while (0 < readtxt && one_search(line) == 0)
	{
		free(line);
		readtxt = get_next_line(fd_map, &line);
	}
	if (readtxt == -1 || !readtxt)
	{
		free(line);
		return (-1);
	}
	tmap = map_reader(fd_map, line);
	close(fd_map);
	if (!tmap)
		return (-1);
	readtxt = map_writer(data, tmap);
	ft_lstclear(&tmap, free);
	return (readtxt); 	
}