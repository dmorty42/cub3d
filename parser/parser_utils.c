/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprovolo <bprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:23:46 by bprovolo          #+#    #+#             */
/*   Updated: 2022/02/01 19:42:29 by bprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*cleaner(t_list **map, char *str)
{
	if (map)
		ft_lstclear(map, free);
	if (str)
		free(str);
	return (NULL);
}

int	list_line(t_list **tmap, char *line)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (!new)
		return (1);
	ft_lstadd_back(tmap, new);
	return (0);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
