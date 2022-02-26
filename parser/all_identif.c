/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_identif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:43:14 by bprovolo          #+#    #+#             */
/*   Updated: 2022/02/01 23:01:04 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h" 

static int	hex_rgb(int red, int green, int blue)
{
	return ((((red * 256) + green) * 256) + blue);
}

static int	my_atoi(char *nbr)
{
	long	num;

	num = 0;
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (-1);
		num = (num * 10) + (*nbr - '0');
		nbr++;
		if (num < 0 || num > 255)
			return (-1);
	}
	return ((int)num);
}

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
	if (my_atoi(rgb[0]) == -1 || my_atoi(rgb[1]) == -1
		|| my_atoi(rgb[2]) == -1)
	{
		identif_free(rgb);
		return (-1);
	}
	i = hex_rgb(my_atoi(rgb[0]), my_atoi(rgb[1]), my_atoi(rgb[2]));
	identif_free(rgb);
	return (i);
}

static int	writer_identif(t_node *data, char **ln)
{
	int	color;

	if (search_texture(data, ln) == -1)
		return (-1);
	color = 0;
	if (!ft_strcmp("F", ln[0]))
	{
		color = ft_rgb(ln[1]);
		if (color == -1)
			return (-1);
		data->tmap.cF++;
		data->tmap.floor = color;
	}
	if (!ft_strcmp("C", ln[0]))
	{
		color = ft_rgb(ln[1]);
		if (color == -1)
			return (-1);
		data->tmap.cC++;
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
	j++;
	if (j > 6)
		return (-1);
	return (writer_identif(data, l_sp));
}
