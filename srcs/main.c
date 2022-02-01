/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:17:19 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/31 20:50:25 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
//	win.mlx = mlx_init();
//	win.win = mlx_new_window(win.mlx, win.widht, win.height, "CUB3D");
//	data->tex = load_texture(data);
    for(int i = 0; data->tmap.cmap[i]; i++)
        printf("%s\n", data->tmap.cmap[i]);
//	draw(data);
//	mlx_hook(win.win, 2, 0, &key_hook, data);
//	mlx_loop(win.mlx);
	// all_clear(data);
}
