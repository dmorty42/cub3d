/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:58:25 by bprovolo          #+#    #+#             */
/*   Updated: 2022/02/01 21:22:29 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	checker_file(char *map)
{
	size_t	len;

	len = st_strlen(map);
	if (len)
		len--;
	while (len && map[len] != '.')
		len--;
	if (!ft_strcmp(map + len + 1, "cub"))
		return (0);
	return (-1);
}
