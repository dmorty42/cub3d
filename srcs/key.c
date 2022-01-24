/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorty <dmorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:46:56 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/25 00:45:37 by dmorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int key_hook(int key, t_node *data)
{
	mlx_clear_window(data->win->mlx, data->win->win);
	if (key == 53)
		exit(0);
	if (key == 13)
	{
		data->plr->y -= 1 * 10;
	}
	else if (key == 0)
	{
		data->plr->dir -= 0.2;
	}
	else if (key == 1)
	{
		data->plr->y += 1 * 10;
	}
	else if (key == 2)
	{
		data->plr->dir += 0.2;
	}
	draw(data);
	return (0);
}

