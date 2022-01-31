/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:57:15 by bprovolo          #+#    #+#             */
/*   Updated: 2022/01/27 19:58:28 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	one_search(char *line)
{
	int	unit;
	int	i;

	unit = 0;
	i = 0;
	while ((line[i] == '1' || line[i] == ' ') && line[i])
	{
		if (line[i] == '1')
			unit = 1;
		i++;
	}
	if (unit > 0 && !line[i])
		return (1);
	return (0);
}
