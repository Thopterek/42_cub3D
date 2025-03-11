/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:47 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/11 09:41:51 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static char	**get_map(char *path)
{
	char	*line;
	int		map_size;
	int		fd;

	map_size = 0;
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

static void	save_pos(t_info *info, int y, int x, int flag)
{
	info->player->position_y = y;
	info->player->position_x = x;
	info->player->orient = flag;
}

static void	find_player(char **map, t_info *info)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			c = map[y][x];
			if (c == 'N')
				save_pos(info, y, x, NORTH);
			else if (c == 'W')
				save_pos(info, y, x, WEST);
			else if (c == 'E')
				save_pos(info, y, x, EAST);
			else if (c == 'S')
				save_pos(info, y, x, SOUTH);
			x++;
		}
		x = 0;
		y++;
	}
}

void	initialization(char **av, t_info *info)
{
	char	*path;

	info->player = bin_malloc(sizeof(t_player));
	info->graphic = bin_malloc(sizeof(t_graphic));
	path = bin_strjoin("./map/", av[1]);
	info->map = get_map(path);
	find_player(info->map, info);
	fill_graphic(info->graphic, path, 0);
	info->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (info->mlx == NULL)
		error_mlx();
}
