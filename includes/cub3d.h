/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorty <dmorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:03:22 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/23 04:41:43 by dmorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

# define SCALE 16

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		widht;
	int		height;
}	t_win;

typedef struct s_plr
{
	int		x;
	int		y;
	float	dir_x;
	float	dir_y;
	float	dir;
}	t_plr;

typedef struct s_node
{
	char	**map;
	t_win	*win;
	t_plr	*plr;
}	t_node;

#endif