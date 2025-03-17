/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:38:13 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/17 13:34:45 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define WIDTH 1980
# define HEIGHT 1080
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define PLAYER_RADIUS 0.1
# define MOVE_SPEED 0.2
# define ROT_SPEED 0.07

/*
	helper for setting
	where player looks
*/
typedef enum s_orient
{
	NORTH,
	WEST,
	EAST,
	SOUTH
}	t_orient;

/*
	information about the player
	- initial position y & x
	- in which way player looks
*/
typedef struct s_player
{
	double	s_position_y;
	double	s_position_x;
	int		orient;
	double	p_direction_x;
	double	p_direction_y;
	double	camera_plane_x;
	double	camera_plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

/*
	information about the textures
	- how big individual texture is
	- path to proper walls
	- colors of floor & ceiling
*/
typedef struct s_graphic
{
	char	*east_path;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		floor;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	int		ceiling;
}	t_graphic;

/*
	raycasting and render
	variables to be used
*/
typedef struct s_raycast
{
	double	camera;
	double	r_direction_x;
	double	r_direction_y;
	int		map_x;
	int		map_y;
	double	side_distance_x;
	double	side_distance_y;
	double	delta_distance_x;
	double	delta_distance_y;
	double	p_wall_distance;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_raycast;

/*
	drawing part of raycast
*/
typedef struct s_draw
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	uint32_t	*pixel_data;
	uint32_t	color;
}	t_draw;

/*
	main structure to be parsed
	plus some sub structures
	- map array
	- mlx initialization
	- controlled player
	- graphics of map
	- algorithm implementation
*/
typedef struct s_info
{
	char			**map;
	t_player		*player;
	t_graphic		*graphic;
	t_raycast		*raycast;
	t_draw			*draw;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture[4];
	uint32_t		**buffer;
}	t_info;

/*
	Initialization for the elements:
	- starting with saving the map (init..)
	- finding player informations (init..)
	- save the paths to textures (fill)
*/
void	initialization(char **av, t_info *info);
void	fill_buffer(t_info *info);
void	fill_graphic(t_graphic *graphic, char *path, int fd);
void	handle_textures(t_info *info);
void	clean_textures(t_info *i, int to_clean);

/*
	potential errors:
	- mlx_init fails
	- mlx_new_image
	- mlx_texture
*/
void	error_mlx(void);
void	error_img(t_info *info);
void	error_tex(t_info *info, int c);

#endif
