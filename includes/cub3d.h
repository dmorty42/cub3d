/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:03:22 by dmorty            #+#    #+#             */
/*   Updated: 2022/01/30 02:34:23 by bprovolo         ###   ########.fr       */
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

typedef struct s_tmap
{
	char	**cmap;
	int		w;
	int		h;
	char	*north;
	char	*west;
	char	*south;
	char	*east;
	int		ceilling;
	int		floor;
}	t_tmap;

typedef struct s_node
{
	char	**map;
	t_win	*win;
	t_plr	*plr;
	t_tmap	tmap;
}	t_node;

int	parse_map(t_node *data, char *av);
size_t	st_strlen(const char *str);
int	double_map( t_list *tmap, size_t size, char **cmap);
int	ft_strcmp(const char *str1, const char *str2);
int	map_checker(t_list *tmap);
int	check_border(char **cmap);
int	one_search(char *line);
int	parse_identif(t_node *data, char *id);
int		all_identif(t_node *data, char **l_sp);
void	identif_free(char **arr);

#endif