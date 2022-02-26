/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:03:22 by dmorty            #+#    #+#             */
/*   Updated: 2022/02/01 22:58:12 by bprovolo         ###   ########.fr       */
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

# define SCALE 64

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		widht;
	int		height;
}	t_win;

typedef struct s_plr
{
	float	x;
	float	y;
	float	dir;
	float	fov;
	float	speed;
	float	delta;
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
	int		cN;
	int		cS;
	int		cW;
	int		cE;
	int		cC;
	int		cF;
}	t_tmap;

typedef struct s_fr
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		width;
	int		height;
	int		en;
	int		scale;
}	t_fr;

typedef struct	s_ray
{
	int		flag;
	float	x;
	float	y;
	float	len;
}	t_ray;

typedef struct s_node
{
	char	**map;
	t_win	*win;
	t_plr	*plr;
	t_tmap	tmap;
	t_fr	*fr;
	t_fr	**tex;
	int		x0;
	int		y0;
	int		ray;
}	t_node;

int		parse_map(t_node *data, char *av);
size_t	st_strlen(const char *str);
int		double_map( t_list *tmap, size_t size, char **cmap);
int		ft_strcmp(const char *str1, const char *str2);
int		map_checker(t_list *tmap);
int		check_border(char **cmap);
int		one_search(char *line);
int		exit_pars_error(char c);
int		parse_identif(t_node *data, char *id);
void	*cleaner(t_list **map, char *str);
int		list_line(t_list **tmap, char *line);
int		all_identif(t_node *data, char **l_sp);
int		search_texture(t_node *data, char **ln);
int		checker_file(char *map);
void	identif_free(char **arr);
int		while_gnl(int fd_map);
void	draw(t_node *data);
int		key_hook(int key, t_node *data);
t_fr	**load_texture(t_node *data);
void	draw(t_node *data);
void	draw_player(t_node *data);
void	draw_map(t_node *data);
void	draw_text(t_node *data, t_ray pt, int off, int i);
void	draw_floor(t_node *data, int x, int y);
void	ray_cast(t_node *data);
void	handler(t_node *data, float dir, t_ray ray);
void	add_texture(t_node *data, float dir, int i, int off);
void	draw_ceil(t_node *data, int x, int y);
void	draw_line(t_node *data, int i, float dir);
void	draw_back(t_node *data, int x, int y, int col);
void	draw_wall(t_node *data, int x, int y, int col);
char	**make_map(t_list *lst, int size);
void	undef(t_fr *fr, int x, int y, unsigned int col);
void	init_plr(t_node *data, int x, int y, char c);
#endif