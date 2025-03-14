/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:38:13 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/14 10:14:08 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define WIDTH 1920
# define HEIGHT 1080
# define SCREENHEIGHT 1000
# define SCREENWIDTH 2000

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
	- in which way he looks
*/
typedef struct s_player
{
	int	position_y;
	int	position_x;
	int	orient;
}	t_player;

/*
	information about the textures
	- how big individual texture is
	- path to proper walls
	- colors of floor & ceiling
*/
typedef struct s_graphic
{
	int		texture_size;
	char	*east_path;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
}	t_graphic;

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
	char		**map;
	t_player	*player;
	t_graphic	*graphic;
	mlx_t		*mlx;
}	t_info;

typedef struct s_play
{
	double		pos_x; //start position
	double		pos_y; //start position
	double		dir_x; //initial direction
	double		dir_y; // initial direction 
	double		plane_x; // raycaster camera plane
	double		plane_y; // raycaster camera plane
	double		time; //time of current frame
	double		oldtime; //time of previous frame
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			texture[8][4096];
	uint32_t	buffer[SCREENHEIGHT][SCREENWIDTH];
}			t_play;

/*
	Initialization for the elements:
	- starting with saving the map (init..)
	- finding player informations (init..)
	- save the paths to textures (fill)
*/
void	initialization(char **av, t_info *info);
void	fill_graphic(t_graphic *graphic, char *path, int fd);

/*
	potential errors:
	- mlx_init fails
*/
void	error_mlx(void);

#endif