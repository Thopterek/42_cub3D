/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_continue_checking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:39:47 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/11 14:02:49 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	test_color(char *line, char *actual, int fd, int flag)
{
	char	**colors;
	int		cc;
	int		tmp;

	cc = 0;
	colors = bin_split(get_element(line), ',');
	while (colors[cc] != NULL)
	{
		tmp = ft_atoi(colors[cc]);
		if (tmp < 0 || tmp > 255)
			error_range(tmp, actual, fd, flag);
		cc++;
	}
	if (cc > 3 || cc < 3)
		error_rgb(cc, actual, fd, flag);
}

static void	check_color(char *line, char *actual, int fd)
{
	static int	floor = 0;
	static int	ceiling = 0;

	if (line == NULL)
	{
		close(fd);
		if (floor != 1 || ceiling != 1)
			error_color_count(floor, ceiling);
		else
			return ;
	}
	if (ft_strncmp(line, "F", 1) == 0)
	{
		test_color(line, actual, fd, FLOOR);
		floor++;
	}
	else if (strncmp(line, "C", 1) == 0)
	{
		test_color(line, actual, fd, CEILING);
		ceiling++;
	}
}

static void	find_colors(char *path, int fd)
{
	char	*line;
	int		cc;

	fd = open_again(path, MAP, path);
	line = get_next_line(fd);
	cc = 0;
	while (line != NULL)
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			line = free_and_get(line, fd);
		else
		{
			while (line[cc] != '\0' && space(line[cc]) == 0)
				cc++;
			if (line[cc] == '\0' || line[cc] == '\n')
				line = free_and_get(line, fd);
			else
			{
				check_color(line + cc, line, 0);
				line = free_and_get(line, fd);
			}
		}
		cc = 0;
	}
	check_color(NULL, NULL, fd);
}

char	**make_map(char *path, int map_size, int fd)
{
	int		cc;
	char	*line;
	char	**map;

	cc = 0;
	fd = open_again(path, MAP, NULL);
	map = bin_malloc(sizeof(char *) * (map_size + 1));
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = free_and_get(line, fd);
		if (line == NULL)
			break ;
		if (ft_strncmp(get_element(line), "1", 1) == 0 || cc != 0)
		{
			map[cc] = bin_strdup(line);
			if (map[cc][ft_strlen(map[cc]) - 1] == '\n')
				map[cc][ft_strlen(map[cc]) - 1] = '\0';
			cc++;
		}
	}
	map[cc] = NULL;
	close(fd);
	return (map);
}

/*
	After mandatory checks we are building the map
	first going through all the information checked
	then getting the size of the map needed for later
*/
void	continue_checking(char *path, int fd, char *line)
{
	int	map_size;

	map_size = 0;
	find_colors(path, 0);
	fd = open_again(path, MAP, NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(get_element(line), "1", 1) == 0)
			map_size++;
		line = free_and_get(line, fd);
	}
	close(fd);
	if (map_size == 0)
		error_nothing();
	look_map(make_map(path, map_size, 0));
}
