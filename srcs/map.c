/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorty <dmorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:07:24 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/25 00:13:12 by dmorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	undef(t_fr *fr, int x, int y, unsigned int col)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_l + x * (fr->bpp >> 3));
	*(unsigned int *)dst = col;
}

char	**make_map(t_list *lst, int size)
{
	char	**map;
	int		i;

	i = -1;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	map[size] = NULL;
	while (lst)
	{
		map[++i] = ft_strdup(lst->content);
		lst = lst->next;
	}
	return (map);
}

//void	parse_map(char **argv, t_node *data)
//{
//	t_list	*map;
//	int		fd;
//	char	*line;
//
//	fd = open(argv[1], O_RDONLY);
//	map = NULL;
//	line = NULL;
//	while (get_next_line(fd, &line))
//	{
//		ft_lstadd_back(&map, ft_lstnew(line));
//	}
//	ft_lstadd_back(&map, ft_lstnew(line));
//	data->map = make_map(map, ft_lstsize(map));
//	close(fd);
//}

void	draw_wall(t_node *data, int x, int y, int col)
{
	int	i;
	int	j;
	int	m;

	m = data->win->widht / (SCALE * 2);
	j = y * m;
	while (j < (y + 1) * m)
	{
		i = x * m;
		while (i < (x + 1) * m)
			undef(data->fr, i++, j, col -= 216 / (int)sqrt(data->fr->scale * 4));
		j++;
	}
}

void	draw_back(t_node *data, int x, int y, int col)
{
	int	i;
	int	j;

	i = x * data->fr->scale / 4;
	j = y * data->fr->scale / 4;
	while (j <= (y + 1) * data->fr->scale / 4)
	{
		i = x * data->fr->scale / 4;
		if (j % 2 == 1)
			while (i <= (x + 1) * data->fr->scale / 4)
				undef(data->fr, i++, j, col);
		else
			while (i <= (x + 1) * data->fr->scale / 4)
				undef(data->fr, i++, j, col * 2);
		col += 512 / (int)sqrt(data->fr->scale / 4);
		j++;
	}
}
