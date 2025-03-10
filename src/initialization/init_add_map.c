/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:47 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/10 12:40:11 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static char	**get_map(char **av)
{
	char	*path;
	char	*line;
	int		map_size;
	int		fd;

	map_size = 0;
	path = bin_strjoin("./map/", av[1]);
	fd = open_again(path, MAP, path);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(get_element(line), "1", 1) == 0)
			map_size++;
		line = free_and_get(line, fd);
	}
	close(fd);
	return (make_map(path, map_size, fd));
}

// check if the map works
// int cc = 0;
// while (map[cc] != NULL)
// {
// 	ft_printf("%s\n", map[cc]);
// 	cc++;
// }
void	initialization(char **av)
{
	char	**map;

	map = get_map(av);
}
