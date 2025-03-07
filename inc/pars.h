/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:19:59 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/07 14:10:13 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H

/*
		Flags
	- for checking files
	- looking at colors
	- coordinates of player
*/
typedef enum e_flags
{
	PNG,
	MAP,
	FLOOR,
	CEILING,
	X,
	Y
}	t_flags;

/*
			Parsing
	checking & saving the map
	- looking for the textures
	- check RGB & build the map
	- testing the actual map
*/
void	before_alloc(int ac, char **av);
void	continue_checking(char *path, int fd, char *line);
void	look_map(char **map);

/*
	helper function for above ones
	- getting the proper fd
	- having a pointer to element
	- looking at spaces
	- freeing and calling gnl
*/
int		open_again(char *path, int flag, char *actual);
char	*get_element(char *line);
int		space(int c);
char	*free_and_get(char *line, int fd);

/*
	Parsing errors in error.c
	related to before_alloc.c
	- not enough arguments
	- wrong map format
	- access denied for map
	- missing indetifier
	- access denied for png
*/
void	error_ac(void);
void	error_format(char **av);
void	error_path(char *path);
void	error_png(char *line, char *actual);
void	error_element(void);

/*
	Parsing errors in more.c
	related to continue_checking.c
	- no floor or ceiling defined
	- too many numbers in color
	- not enough indetifiers
	- no map was found
*/
void	error_rgb(int cc, char *line, int fd, int flag);
void	error_range(int tmp, char *line, int fd, int flag);
void	error_color_count(int floor, int ceiling);
void	error_nothing(void);

/*
	More errors in problem.c
	related to look_map.c
	- invalid character
	- too many players
	- unclosed walls
*/
void	error_char(char c);
void	error_orient(int orient);
void	error_walls(int space);

#endif