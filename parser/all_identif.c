/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_identif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:43:14 by bprovolo          #+#    #+#             */
/*   Updated: 2022/01/30 02:48:58 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h" 

static int	ft_rgb(char *str)
{
	int		i;
	char	**rgb;

	rgb = ft_split(str, ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
	{
		identif_free(rgb);
		return (-1);
	}
	if (ft_atoi(rgb[0]) == -1 || ft_atoi(rgb[1]) == -1
		|| ft_atoi(rgb[2]) == -1)
	{
		identif_free(rgb);
		return (-1);
	}
	i = ft_atoi(rgb[0]) + ft_atoi(rgb[1]) + ft_atoi(rgb[2]);
	identif_free(rgb);
	return (i);
} 


static int	writer_identif(t_node *data, char **ln)
{
	int				color;
	// const t_texture	*texture[] = {
	// 	&data->textures.north, &data->textures.south,
	// 	&data->textures.west, &data->textures.east
	// };

	if (!ft_strcmp("WE", ln[0]))
			data->tmap.west = ln[1];
	if (!ft_strcmp("SO", ln[0]))
			data->tmap.south = ln[1];
	if (!ft_strcmp("EA", ln[0]))
		data->tmap.east = ln[1];
	if (!ft_strcmp("NO", ln[0]))
		data->tmap.north = ln[1];
	color = 0;
	// if (iter < 4)
	// 	if (get_texture(data->mlx,
	// 			(t_texture *)texture[iter], ln_prt[1]) == -1)
	// 		return (-1);
	// if (iter == 4 || iter == 5)
	
	// if ((iter == 4 || iter == 5) && color == -1)
	// 	return (-1);
	// if ((j == 4 && data->tmap.floor != -1)
	// 	|| (j == 5 && data->tmap.ceilling != -1))
	// 	return (-1);
	if (!ft_strcmp("F", ln[0]))
	{
		color = ft_rgb(ln[1]);
		data->tmap.floor = color;
	}

	if (!ft_strcmp("C", ln[0]))
	{
		color = ft_rgb(ln[1]);
		data->tmap.ceilling = color;
	}
	return (0);
}


int	all_identif(t_node *data, char **l_sp)
{
	int	i;
	int	j;

	i = 0;
	while (l_sp[i])
		i++;
	if (i != 2)
		return (-1);
	j = 0;
	// while (j < 6)
	// {
		
	// 		break ;
		j ++;
	// }
	if (j > 6)
		return (-1);
	return (writer_identif(data, l_sp));
}
