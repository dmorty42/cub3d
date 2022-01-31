/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorty <dmorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:03:23 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/25 00:22:46 by dmorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_cast(t_node *data)
{
	float	dir;
	t_ray	ray;

	dir = data->plr->dir - data->plr->fov / 2;
	while (dir < (data->plr->dir + data->plr->fov / 2))
	{
		ray.len = 0;
		ray.x = data->plr->x;
		ray.y = data->plr->y;
		while (data->map[(int)(ray.y) >> 6][(int)(ray.x) >> 6] != '1')
		{
			ray.x += cosf(dir);
			ray.y += sinf(dir);
			ray.len++;
		}
		handler(data, dir, ray);
		dir += data->plr->delta;
	}
}

void	draw_line(t_node *data, int i, float dir)
{
	float	x0;
	float	y0;
	int		x;
	int		y;
	float	del;

	x0 = data->win->widht / 2;
	y0 = data->win->height / 2;
	del = data->fr->scale / 2 * data->win->height / (i * cos(dir));
	if (del > data->win->height / 2)
		del = data->win->height / 2;
	y = y0 - del;
	while (y < y0 + del)
	{
		x = x0 - dir * data->win->widht / data->plr->fov;
		undef(data->fr, x, y, 0x0000ff);
		y++;
	}
}

void	draw_ceil(t_node *data, int x, int y)
{
	int	j;

	if (y > data->win->height)
		y = data->win->height;
	j = 1;
	while (j < y)
	{
		undef(data->fr, x, j, 0xFF00FF);
		j++;
	}
}

void	add_texture(t_node *data, float dir, int ray, int off)
{
	int	i;
	float	half = (SCALE >> 1) * data->win->height / (ray * cos(dir));
	float	wall = half * 2;
	t_ray	point;


	i = 0;
	point.x = (data->x0 - dir * data->win->widht / data->plr->fov);
	point.y = data->y0 - half - 1;
	draw_ceil(data, point.x, point.y);
	while (++point.y < data->y0 + half)
	{
		draw_text(data, point, off, i++ / (wall / SCALE));
	}
	draw_floor(data, point.x, point.y - 1);
}

void	handler(t_node *data, float dir, t_ray ray)
{
	data->ray = ray.len;
	if ((int)(ray.x - cos(dir)) >> 6 == (int)ray.x >> 6)
		add_texture(data, data->plr->dir - dir, ray.len, (int)ray.x & 63);
	else
		add_texture(data, data->plr->dir - dir, ray.len, (int)ray.y & 63);
}
