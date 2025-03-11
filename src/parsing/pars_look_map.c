/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_look_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/11 14:14:03 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	big_if(char c)
{
	if (c != '1' && c != '0' && c != 'N'
		&& c != 'S' && c != 'E' && c != 'W'
		&& space(c) != 0)
	{
		error_char(c);
	}
}

static void	valid_chars(char **map)
{
	int		orient;
	char	c;
	int		line;
	int		i;

	line = 0;
	i = 0;
	orient = 0;
	while (map[line] != NULL)
	{
		while (map[line][i] != '\0')
		{
			c = map[line][i];
			big_if(c);
			if (c != '1' && c != '0' && space(c) != 0)
				orient++;
			i++;
		}
		i = 0;
		line++;
	}
	if (orient != 1)
		error_orient(orient);
}

static void	ffill(char **map, int x, int y, int *out)
{
	if (y < 0 || x < 0 || map[y] == NULL
		|| map[y][x] == '1' || map[y][x] == 'V')
	{
		if (map[y] == NULL || y < 0 || x < 0)
			*out += 1;
		return ;
	}
	if (space(map[y][x]) == 0 || map[y][x] == '\0')
	{
		*out += 1;
		return ;
	}
	if (map[y][x] == '\0')
		return ;
	map[y][x] = 'V';
	ffill(map, x + 1, y, out);
	ffill(map, x - 1, y, out);
	ffill(map, x, y + 1, out);
	ffill(map, x, y - 1, out);
}

static int	find_p(int flag, char **map)
{
	char	c;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			c = map[y][x];
			if (c != '1' && c != '0' && space(c) != 0)
			{
				if (flag == X)
					return (x);
				else if (flag == Y)
					return (y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (EXIT_FAILURE);
}

/*
	Except for the map,
	each type of information
	from an element can be separated
	by one or more space(s).
*/
void	look_map(char **map)
{
	int	out;

	out = 0;
	valid_chars(map);
	ffill(map, find_p(X, map), find_p(Y, map), &out);
	if (out != 0)
		error_walls(out);
}
