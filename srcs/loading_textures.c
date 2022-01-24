/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorty <dmorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:59:44 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/24 23:00:07 by dmorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_fr	**load_texture(t_node *data)
{
	int		i;
	t_fr	**tex;
	char	**texture;

	texture = (char **)malloc(sizeof(char *) * 5);
	texture[0] = ft_strdup("./imgs/bluestone.xpm");
	texture[1] = ft_strdup("./imgs/colorstone.xpm");
	texture[2] = ft_strdup("./imgs/greystone.xpm");
	texture[3] = ft_strdup("./imgs/purplestone.xpm");
	texture[4] = NULL;
	i = 0;
	tex = (t_fr **)malloc(sizeof(t_fr *));
	while (i < 4)
	{
		tex[i] = (t_fr *)malloc(sizeof(t_fr));
		tex[i]->img = mlx_xpm_file_to_image(data->win->mlx, texture[i], \
								&tex[i]->width, &tex[i]->height);
		tex[i]->addr = mlx_get_data_addr(tex[i]->img, &tex[i]->bpp, &tex[i]->line_l, &tex[i]->en);
		i++;
	}
	return (tex);
}
