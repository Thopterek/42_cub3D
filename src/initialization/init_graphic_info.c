/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:06:38 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/17 11:34:33 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	grab_path(t_graphic *graphic, char *line)
{
	if (line == NULL)
		return ;
	if (ft_strncmp(line, "NO", 2) == 0)
		graphic->north_path = bin_strdup(get_element(line + 2));
	else if (ft_strncmp(line, "SO", 2) == 0)
		graphic->south_path = bin_strdup(get_element(line + 2));
	else if (ft_strncmp(line, "WE", 2) == 0)
		graphic->west_path = bin_strdup(get_element(line + 2));
	else if (ft_strncmp(line, "EA", 2) == 0)
		graphic->east_path = bin_strdup(get_element(line + 2));
}

static int	rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	grab_colors(t_graphic *g, char *line)
{
	char	**colors;

	if (line == NULL)
		return ;
	if (ft_strncmp(line, "F", 1) == 0)
	{
		colors = bin_split(get_element(line + 1), ',');
		g->floor_red = ft_atoi(colors[0]);
		g->floor_green = ft_atoi(colors[1]);
		g->floor_blue = ft_atoi(colors[2]);
		g->floor = rgb(g->floor_red, g->floor_green, g->floor_blue, 255);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		colors = bin_split(get_element(line + 1), ',');
		g->ceiling_red = ft_atoi(colors[0]);
		g->ceiling_green = ft_atoi(colors[1]);
		g->ceiling_blue = ft_atoi(colors[2]);
		g->ceiling = rgb(g->ceiling_red, g->ceiling_green,
				g->ceiling_blue, 255);
	}
}

void	fill_buffer(t_info *info)
{
	int	cc;

	cc = 0;
	info->buffer = bin_malloc(sizeof(uint32_t *) * HEIGHT);
	while (cc < HEIGHT)
	{
		info->buffer[cc] = bin_malloc(sizeof(uint32_t) * WIDTH);
		cc++;
	}
}

void	fill_graphic(t_graphic *graphic, char *path, int fd)
{
	int		cc;
	char	*line;

	cc = 0;
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
			if (line[cc] != '\0')
			{
				grab_path(graphic, line + cc);
				grab_colors(graphic, line + cc);
			}
			line = free_and_get(line, fd);
		}
		cc = 0;
	}
	close(fd);
}
