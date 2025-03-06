/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:19:59 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/06 14:37:58 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H

/*
		Flags
	- for checking files
	- looking at colors
*/
typedef enum e_flags
{
	PNG,
	MAP,
	FLOOR,
	CEILING
}	t_flags;

/*
			Parsing
	checking & saving the map
	- looking for the textures
	- helper function to get fd
	- check RGB & making the map
	- checking the actual map
*/
void	before_alloc(int ac, char **av);
int		open_again(char *path, int flag, char *actual);
void	continue_checking(char *path);
void	look_map(char **map);

/*
	Parsing errors from before.c
	- not enough arguments
	- wrong map format
	- access denied for map
	- missing indetifier
	- access denied for png
*/
void	error_ac(void);
void	error_format(char **av);
void	error_path(char *path);
void	error_element(char *line, char *element);
void	error_png(char *line, char *actual);

/*
	Parsing errors from more.c
	- no floor or ceiling defined
	- too many numbers in color
*/
void	error_updown(char *no_newline, char flag, char *line);
void	error_rgb(int cc, char *line);
void	error_range(int tmp, char *line);

#endif