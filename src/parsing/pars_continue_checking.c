/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_continue_checking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:39:47 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/06 12:36:44 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	look_for_range(char **colors, char *line)
{
	int	cc;

	cc = 0;
	while (colors[cc] != NULL)
	{
		cc++;
	}
	if (cc > 3 || cc < 3)
		error_rgb(cc, line);
}

static void	check_color(char *line, int flag)
{
	char	**colors;
	char	*no_newline;
	int		cc;

	cc = 0;
	no_newline = bin_strdup(line);
	while (no_newline[cc + 1] != '\0')
		cc++;
	if (no_newline[cc] == '\n')
		no_newline[cc] = '\0';
	if (flag == FLOOR)
	{
		if (strncmp(no_newline, "F", 1) != 0)
			error_updown(no_newline, 'F', line);
	}
	else if (flag == CEILING)
	{
		if (strncmp(no_newline, "C", 1) != 0)
			error_updown(no_newline, 'C', line);
	}
	colors = bin_split(no_newline + 2, ',');
	look_for_range(colors, line);
}

static void	find_colors(char *path)
{
	int		cc;
	int		fd;
	char	*line;

	cc = 0;
	fd = open_again(path, MAP, NULL);
	line = get_next_line(fd);
	while (line != NULL && cc != 5)
	{
		free(line);
		line = get_next_line(fd);
		cc++;
	}
	check_color(line, FLOOR);
	free(line);
	line = get_next_line(fd);
	check_color(line, CEILING);
	free(line);
}

void	continue_checking(char *path)
{
	find_colors(path);
}
