/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:06:38 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/10 17:42:42 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void grab_path(t_graphic *graphic, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		graphic->north_path = bin_strdup(get_element(line + 2));
	else if (ft_strncmp(line, "SO", 2) == 0)
		graphic->south_path = bin_strdup(get_element(line + 2));
	else if (ft_strncmp(line, "WE", 2) == 0)
		graphic->west_path = bin_strdup(get_element(line + 2));
	else if (ft_strncmp(line, "EA", 2) == 0)
		graphic->east_path = bin_strdup(get_element(line + 2));
}

static void	grab_colors(t_graphic *graphic, char *line)
{
	char	**colors;

	if (ft_strncmp(line, "F", 1) == 0)
	{
		colors = bin_split(get_element(line + 1), ',');
		graphic->floor_red = ft_atoi(colors[0]);
		graphic->floor_green = ft_atoi(colors[1]);
		graphic->floor_blue = ft_atoi(colors[2]);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		colors = bin_split(get_element(line + 1), ',');
		graphic->ceiling_red = ft_atoi(colors[0]);
		graphic->ceiling_green = ft_atoi(colors[1]);
		graphic->ceiling_blue = ft_atoi(colors[2]);
	}
}

void	fill_graphic(t_graphic *graphic, char *path, int fd)
{
	int		cc;
	char	*line;

	fd = open_again(path, MAP, path);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			line = free_and_get(line, fd);
		else
		{
			while (line[cc] != '\0' && space(line[cc]) == 0)
				cc++;
			grab_path(graphic, line + cc);
			grab_colors(graphic, line + cc);
			line = free_and_get(line, fd);
		}
		cc = 0;
	}
	close(fd);
}
