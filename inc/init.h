/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:38:13 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/10 17:44:58 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

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

/*
	Initialization for the elements:
	- starting with saving the map (init..)
	- finding player informations (init..)
	- save the paths to textures (fill)
*/
void	initialization(char **av, t_info **info);
void	fill_graphic(t_graphic *graphic, char *path, int fd);

#endif