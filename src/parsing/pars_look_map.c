/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_look_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/07 11:53:37 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	valid_chars(char **map, char c, int line, int i)
{
	int	orient;

	orient = 0;
	line = 0;
	i = 0;
	while (map[line] != NULL)
	{
		while (map[line][i] != '\0')
		{
			c = map[line][i];
			if (c != '1' && c != '0' && c != 'N'
				&& c != 'S' && c != 'E' && c != 'W'
				&& space(c) != 0)
			{
				error_char(c);
			}
			else if (c != '1' && c != '0' && space(c) != 0)
				orient++;
			i++;
		}
		i = 0;
		line++;
	}
	if (orient != 1)
		error_orient(orient);
}

// int cc = 0;
// while (map[cc] != NULL)
// 	ft_printf("%s\n", map[cc++]);
void	look_map(char **map)
{
	valid_chars(map, '0', 0, 0);
}
