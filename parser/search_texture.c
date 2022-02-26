/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:15:32 by bprovolo          #+#    #+#             */
/*   Updated: 2022/02/01 23:02:37 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	search_texture(t_node *data, char **ln)
{
	if (!ft_strcmp("WE", ln[0]))
	{
		data->tmap.west = ft_strdup(ln[1]);
		data->tmap.cW++;
	}
	else if (!ft_strcmp("SO", ln[0]))
	{
		data->tmap.south = ft_strdup(ln[1]);
		data->tmap.cS++;
	}
	else if (!ft_strcmp("EA", ln[0]))
	{
		data->tmap.east = ft_strdup(ln[1]);
		data->tmap.cE++;
	}
	else if (!ft_strcmp("NO", ln[0]))
	{
		data->tmap.north = ft_strdup(ln[1]);
		data->tmap.cN++;
	}
	return (0);
}
