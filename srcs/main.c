/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:17:19 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/27 19:57:51 by bprovolo         ###   ########.fr       */
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
	data->plr->x = x * SCALE;
	data->plr->y = y * SCALE;
	if (c == 'N')
		data->plr->dir = 3 * M_PI_2;
	else if (c == 'W')
		data->plr->dir = 0;
	else if (c == 'S')
		data->plr->dir = M_PI_2;
	else if (c == 'E')
		data->plr->dir = M_PI;
}

void	ray_cast(t_node *data)
{
	float	x;
	float	y;
	float	dir;
	int 	i;

	x = data->plr->x;
	y = data->plr->y;
	dir = data->plr->dir - M_PI_4;
	while (dir < (data->plr->dir + M_PI_4))
	{
		i = 0;
		while (data->map[(int)y / SCALE][(int)x / SCALE] == '1')
		{
			mlx_pixel_put(data->win->mlx, data->win->win, x, y, 0xFF00BB);
			x += cos(dir);
			y += sin(dir);
		}
		x = data->plr->x;
		y = data->plr->y;
		dir += 0.03;
	}
}

void	draw_player(t_node *data)
{
	int	x;
	int	y;

	x = data->plr->x;
	y = data->plr->y;
	while (y <= data->plr->y + sqrt(SCALE))
	{
		x = data->plr->x;
		while (x <= data->plr->x + sqrt(SCALE))
			mlx_pixel_put(data->win->mlx, data->win->win, x++, y, 0xFF7731);
		y++;
	}
	ray_cast(data);
}

void	draw_map(t_node *data)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_wall(data, x, y, 0XFFFFFF);
			else if (data->map[y][x] == '0')
				draw_back(data, x, y, 0x99cccc);
			else if (data->map[y][x] == 'N')
			{
				init_plr(data, x, y, data->map[y][x]);
				data->map[y][x] = '0';
				draw_back(data, x, y, 0x99cccc);
			}
			x++;
		}
		y++;
	}
	draw_player(data);
}

int key_hook(int key, t_node *data)
{
	mlx_clear_window(data->win->mlx, data->win->win);
	if (key == 53)
		exit(0);
	if (key == 13)
	{
		data->plr->y -= 3;
		while (data->map[data->plr->y / SCALE][data->plr->x / SCALE] == '1')
			data->plr->y += 1;
	}
	else if (key == 0)
	{
		data->plr->x -= 3;
		while (data->map[data->plr->y / SCALE][data->plr->x / SCALE] == '1')
			data->plr->x += 1;
	}
	else if (key == 1)
	{
		data->plr->y += 3;
		while (data->map[data->plr->y / SCALE][data->plr->x / SCALE] == '1')
			data->plr->y -= 1;
	}
	else if (key == 2)
	{
		data->plr->x += 3;
		while (data->map[data->plr->y / SCALE][data->plr->x / SCALE] == '1')
			data->plr->x -= 1;
	}
	draw_map(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*data;
	t_win	win;

	data = (t_node *)malloc(sizeof(t_node));
	data->plr = (t_plr *)malloc(sizeof(t_plr));
	win.mlx = NULL;
	win.win = NULL;
	win.height = 720;
	win.widht = 1080;
	data->win = &win;
	if (argc != 2)
		perror("Error: wrong number of arguments\n");
	if (parse_map(data, argv[1]) == -1)
		perror("Error: invalid map\n");
	if (parse_identif(data, argv[1]) == -1)
		perror("Error:");
	{
		/* code */
	}
	
	int y = 0;
	while (y < 14)
	{
		y++;
		int i = 0;
		while (i < 45)
		{
			printf("%c", data->tmap.cmap[y][i]);
			i++;
		}
		printf("\n");
	}
	// win.mlx = mlx_init();
	// win.win = mlx_new_window(win.mlx, win.widht, win.height, "CUB3D");
	// draw_map(data);

	// mlx_hook(win.win, 2, 0, &key_hook, data);
	// mlx_loop(win.mlx);
	// all_clear(data);
}
