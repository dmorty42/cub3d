/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorty <dmorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:00:26 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/25 00:20:44 by dmorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw(t_node *data)
{
	data->fr->img = mlx_new_image(data->win->mlx, data->win->widht, data->win->height);
	data->fr->addr = mlx_get_data_addr(data->fr->img, &data->fr->bpp, &data->fr->line_l, &data->fr->en);
	draw_map(data);
//	ray_cast(data);
//	draw_player(data);
	mlx_put_image_to_window(data->win->mlx, data->win->win, data->fr->img, 0, 0);
	mlx_destroy_image(data->win->mlx, data->fr->img);
}

void	draw_player(t_node *data)
{
	int	x;
	int	y;

	x = data->plr->x;
	y = data->plr->y;
	while (y <= data->plr->y + sqrt(data->fr->scale))
	{
		x = data->plr->x;
		while (x <= data->plr->x + sqrt(data->fr->scale))
			undef(data->fr, x++ / 4, y / 4, 0xFF7731);
		y++;
	}
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
			if (data->map[y][x] == 'N')
			{
				init_plr(data, x, y, data->map[y][x]);
				data->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	draw_text(t_node *data, t_ray pt, int off, int i)
{
	char	*win;
	char	*tex;
	int		shade;

	shade = data->ray >> 2;
	if (pt.y >= 0 && pt.y < data->win->height)
	{
		tex = data->tex[0]->addr + (int)(i * data->tex[0]->line_l + off * (data->tex[0]->bpp >> 3));
		if (*(int *)tex == 0x010101)
			return ;
		win = data->fr->addr + ((int)pt.y * data->fr->line_l + (int)pt.x * (data->fr->bpp >> 3));
		*(int *)win = *(int *)tex;
	}
}

void	draw_floor(t_node *data, int x, int y)
{
	int	j;

	j = data->win->height - 1;
	while (j >= 0 && j > y)
	{
		undef(data->fr, x, j, 0xAA00AA);
		j--;
	}
}
