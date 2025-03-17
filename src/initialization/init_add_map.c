/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:47 by ndziadzi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/14 19:34:51 by ndziadzi         ###   ########.fr       */
=======
/*   Updated: 2025/03/17 16:26:10 by ndziadzi         ###   ########.fr       */
>>>>>>> 5626cfe41a44434ce227dcdab3935e03649cf813
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
		info->player->p_direction_x = 0;
		info->player->p_direction_y = -1;
		info->player->camera_plane_x = -0.66;
		info->player->camera_plane_y = 0;
	}
	else if (flag == SOUTH)
	{
		info->player->p_direction_x = 0;
		info->player->p_direction_y = 1;
		info->player->camera_plane_x = 0.66;
		info->player->camera_plane_y = 0;
	}
}

static void	save_pos(t_info *info, int y, int x, int flag)
{
	info->player->s_position_y = y + 0.5;
	info->player->s_position_x = x + 0.5;
	info->player->orient = flag;
	update_look(info, flag);
	if (flag == EAST)
	{
		info->player->p_direction_x = -1;
		info->player->p_direction_y = 0;
		info->player->camera_plane_x = 0;
		info->player->camera_plane_y = 0.66;
	}
	else if (flag == WEST)
	{
		info->player->p_direction_x = 1;
		info->player->p_direction_y = 0;
		info->player->camera_plane_x = 0;
		info->player->camera_plane_y = -0.66;
	}
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
	ft_printf("after mallocs for structures\n");
	path = bin_strjoin("./map/", av[1]);
	ft_printf("getting the map\n");
	info->map = get_map(path);
	ft_printf("finding the player\n");
	find_player(info->map, info);
<<<<<<< HEAD
	info->player->camera_plane_x = 0;
	info->player->camera_plane_y = 0.66;
	info->player->move_speed = 0.1;
	info->player->rot_speed = 0.05;
	ft_printf("filling out the graphics\n");
=======
	info->player->move_speed = MOVE_SPEED;
	info->player->rot_speed = ROT_SPEED;
	fill_buffer(info);
>>>>>>> 5626cfe41a44434ce227dcdab3935e03649cf813
	fill_graphic(info->graphic, path, 0);
	ft_printf("mlx_init\n");
	ft_printf("WIDTH: %d, HEIGHT: %d\n", WIDTH, HEIGHT);
	info->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (info->mlx == NULL)
		error_mlx();
	ft_printf("mlx new image\n");
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (info->img == NULL)
	{
		clean_textures(info, 4);
		error_img(info);
	}
	ft_printf("mlx to window\n");
	mlx_image_to_window(info->mlx, info->img, 0, 0);
	ft_printf("handling textures\n");
	handle_textures(info);
}
