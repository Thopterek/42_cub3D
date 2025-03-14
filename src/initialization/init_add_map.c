/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:47 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/14 18:23:42 by ndziadzi         ###   ########.fr       */
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

static void	update_look(t_info *info, int flag)
{
	if (flag == NORTH)
	{
		info->player->p_direction_x = -1;
		info->player->p_direction_y = 0;
	}
	else if (flag == SOUTH)
	{
		info->player->p_direction_x = 1;
		info->player->p_direction_y = 0;
	}
	else if (flag == EAST)
	{
		info->player->p_direction_x = 0;
		info->player->p_direction_y = 1;
	}
	else if (flag == WEST)
	{
		info->player->p_direction_x = 0;
		info->player->p_direction_y = -1;
	}
}

static void	save_pos(t_info *info, int y, int x, int flag)
{
	info->player->s_position_y = y;
	info->player->s_position_x = x;
	info->player->orient = flag;
	update_look(info, flag);
}

static void	find_player(char **map, t_info *info)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '\0')
				break ;
			if (map[y][x] == 'N')
				save_pos(info, y, x, NORTH);
			else if (map[y][x] == 'W')
				save_pos(info, y, x, WEST);
			else if (map[y][x] == 'E')
				save_pos(info, y, x, EAST);
			else if (map[y][x] == 'S')
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
	info->raycast = bin_malloc(sizeof(t_raycast));
	info->draw = bin_malloc(sizeof(t_draw));
	path = bin_strjoin("./map/", av[1]);
	info->map = get_map(path);
	find_player(info->map, info);
	info->player->camera_plane_x = 0;
	info->player->camera_plane_y = 0.66;
	info->player->move_speed = 0.1;
	info->player->rot_speed = 0.05;
	fill_graphic(info->graphic, path, 0);
	info->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (info->mlx == NULL)
		error_mlx();
	handle_textures(info);
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (info->img == NULL)
	{
		clean_textures(info, 4);
		error_img(info);
	}
	mlx_image_to_window(info->mlx, info->img, 0, 0);
}
