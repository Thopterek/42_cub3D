/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_look_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/06 15:57:54 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	remove_newline(char **map)
{
	int	cc;

	cc = 0;
	while (map[cc] != NULL)
	{
		if (map[cc][ft_strlen(map[cc]) - 1] == '\n')
			map[cc][ft_strlen(map[cc]) - 1] = '\0';
		cc++;
	}
}

void	look_map(char **map)
{
	remove_newline(map);
}
