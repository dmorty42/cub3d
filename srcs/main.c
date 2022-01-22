/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorty <dmorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:17:19 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/22 20:51:53 by dmorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	ft_clear_lst(t_list *map)
{
	t_list	*temp;

	while (map)
	{
		temp = map;
		map = map->next;
		free(temp->content);
		temp->content = NULL;
		temp->next = NULL;
		free(temp);
	}
}

void	parse_map(char **argv, t_node *data)
{
	t_list	*map;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	map = NULL;
	line = NULL;
	data->mlx = NULL;
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&map, ft_lstnew(line));
	}
	ft_lstadd_back(&map, ft_lstnew(line));
	data->map = make_map(map, ft_lstsize(map));
	close(fd);
}

void	all_clear(t_node *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		free(data->map);
	}
	data->map = NULL;
}

void	put_square(t_node *data, int x, int y, int color)
{
	int	i;
	int	j;

	j = y;
	while (j < y + 32)
	{
		i = x;
		while (i < x + 32)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, color);
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*data;
	int	x;
	int	y;

	y = 0;
	x = 0;
	data = (t_node *)malloc(sizeof(t_node));
	if (argc == 2)
	{
		parse_map(argv, data);
	}
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "CUB3D");
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				put_square(data, (x + 6) * 42, (y + 6) * 42, 0XFFFFFF);
			else
				put_square(data, (x + 6) * 42, (y + 6) * 42, 0X000000);
			x++;
		}
		y++;
	}
	// draw_map(data);
	mlx_loop(data->mlx);
	all_clear(data);
}
