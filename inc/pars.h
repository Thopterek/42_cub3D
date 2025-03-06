/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:19:59 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/06 18:55:46 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H

/*
		Flags
	- for checking files
	- looking at colors
	- elements count to find
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
	- check RGB & making the map
	- checking the actual map
*/
void	before_alloc(int ac, char **av);
void	continue_checking(char *path);
void	look_map(char **map);

/*
	helper function for above ones
	- getting the proper fd
	- having a pointer to element
*/
int		open_again(char *path, int flag, char *actual);
char	*get_element(char *line);
int		space(int c);
char	*free_and_get(char *line, int fd);
/*
	Parsing errors in error.c
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

/*
	Parsing errors in more.c
	- no floor or ceiling defined
	- too many numbers in color
*/
void	error_updown(char *no_newline, char flag, char *line);
void	error_rgb(int cc, char *line);
void	error_range(int tmp, char *line);
void	error_element(void);

#endif