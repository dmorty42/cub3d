/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:17:19 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/30 02:49:34 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// char	**make_map(t_list *lst, int size)
// {
// 	char	**map;
// 	int		i;

// 	i = -1;
// 	map = (char **)malloc(sizeof(char *) * (size + 1));
// 	map[size] = NULL;
// 	while (lst)
// 	{
// 		map[++i] = ft_strdup(lst->content);
// 		lst = lst->next;
// 	}
// 	return (map);
// }

// void	parse_map(char **argv, t_node *data)
// {
// 	t_list	*map;
// 	int		fd;
// 	char	*line;

// 	fd = open(argv[1], O_RDONLY);
// 	map = NULL;
// 	line = NULL;
// 	while (get_next_line(fd, &line))
// 	{
// 		ft_lstadd_back(&map, ft_lstnew(line));
// 	}
// 	ft_lstadd_back(&map, ft_lstnew(line));
// 	data->map = make_map(map, ft_lstsize(map));
// 	close(fd);
// }

// void	all_clear(t_node *data)
// {
// 	int	i;

// 	i = 0;
// 	if (data->map)
// 	{
// 		free(data->map);
// 	}
// 	data->map = NULL;
// }

void	draw_wall(t_node *data, int x, int y, int col)
{
	int	i;
	int	j;

	i = x * SCALE;
	j = y * SCALE;
	while (j < (y + 1) * SCALE)
	{
		i = x * SCALE;
		while (i < (x + 1) * SCALE)
			mlx_pixel_put(data->win->mlx, data->win->win, i++, j, col);
		j++;
	}
}

void	draw_back(t_node *data, int x, int y, int col)
{
	int	i;
	int	j;

	i = x * SCALE;
	j = y * SCALE;
	while (j <= (y + 1) * SCALE)
	{
		i = x * SCALE;
		if (j % 2 == 1)
			while (i <= (x + 1) * SCALE)
				mlx_pixel_put(data->win->mlx, data->win->win, i++, j, col);
		else
			while (i <= (x + 1) * SCALE)
				mlx_pixel_put(data->win->mlx, data->win->win, i++, j, col * 2);
		col += 512 / (int)sqrt(SCALE);
		j++;
	}
}


void	init_plr(t_node *data, int x, int y, char c)
{
	data->plr->x = x * SCALE + (SCALE >> 1);
	data->plr->y = y * SCALE + (SCALE >> 1);
	data->plr->fov = 66 * M_PI / 180;
	data->plr->speed = sqrt(SCALE) * 2;
	data->plr->delta = (float)(data->plr->fov / (data->win->widht * 1.2));
	if (c == 'N')
		data->plr->dir = 3 * M_PI_2;
	else if (c == 'W')
		data->plr->dir = 0;
	else if (c == 'S')
		data->plr->dir = M_PI_2;
	else if (c == 'E')
		data->plr->dir = M_PI;
}


int	main(int argc, char **argv)
{
	t_node	*data;
	t_win	win;

	data = (t_node *)malloc(sizeof(t_node));
	data->plr = (t_plr *)malloc(sizeof(t_plr));
	data->fr = (t_fr *)malloc(sizeof(t_fr));
	win.mlx = NULL;
	win.win = NULL;
	win.height = 720;
	win.widht = 1080;
	data->fr->scale = win.widht / 30;
	data->win = &win;
	if (argc != 2)
		perror("Error: wrong number of arguments\n");
	if (parse_identif(data, argv[1]) == -1)
		perror("Error:");
	if (parse_map(data, argv[1]) == -1)
		perror("Error: invalid map\n");
	data->x0 = data->win->widht >> 1;
	data->y0 = data->win->height >> 1;
	if (argc == 2)
	{
		y++;
		int i = 0;
		while (i < 45)
		{
			printf("|%c", data->tmap.cmap[y][i]);
			i++;
		}
		printf("\n");
	}
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.widht, win.height, "CUB3D");
	data->tex = load_texture(data);
	draw(data);
	mlx_hook(win.win, 2, 0, &key_hook, data);
	mlx_loop(win.mlx);
	// all_clear(data);
}
