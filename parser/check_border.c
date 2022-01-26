

#include "../includes/cub3d.h"

static int	check_char(char c)
{
	if ('0' == c || 'N' == c || 
        'S' == c || 'W' == c || 'E' == c)
		return (0);
	return (-1);
}

int	check_border(char **cmap)
{
	int	i;
	int	j;

	i = -1;
	while (cmap[++i])
	{
		j = -1;
		while (cmap[i][++j])
			if (!check_char(cmap[i][j]) && (cmap[i][j + 1] == ' '
					|| cmap[i][j - 1] == ' ' || cmap[i + 1][j] == ' '
					|| cmap[i - 1][j] == ' ' || cmap[i + 1][j + 1] == ' '
					|| cmap[i + 1][j - 1] == ' ' || cmap[i - 1][j - 1] == ' '
					|| cmap[i - 1][j + 1] == ' '))
				return (-1);
	}
	return (0);
}