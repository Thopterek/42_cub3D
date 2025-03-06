/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_before_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:34:57 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/06 14:34:37 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static int	check_format(char **av)
{
	int	cc;

	cc = 0;
	if (ft_strnstr(av[1], ".cub", ft_strlen(av[1])) == NULL)
		return (1);
	while (av[1][cc + 1] != '\0')
		cc++;
	if (av[1][cc] != 'b' && av[1][cc - 1] != 'u'
		&& av[1][cc - 2] != 'c' && av[1][cc - 3] != '.')
		return (2);
	return (EXIT_SUCCESS);
}

static char	*png_path(char *line)
{
	char	*path;
	int		cc;

	cc = 0;
	path = bin_strdup(line + 3);
	while (path[cc + 1] != '\0')
		cc++;
	if (path[cc] == '\n')
		path[cc] = '\0';
	return (path);
}

static void	look_for_elements(char *path)
{
	char	*line;
	int		fd;

	fd = open_again(path, MAP, path);
	line = get_next_line(fd);
	if (ft_strncmp(line, "NO", 2) != 0)
		error_element(line, "NO");
	open_again(png_path(line), PNG, line);
	free(line);
	line = get_next_line(fd);
	if (ft_strncmp(line, "SO", 2) != 0)
		error_element(line, "SO");
	open_again(png_path(line), PNG, line);
	free(line);
	line = get_next_line(fd);
	if (ft_strncmp(line, "WE", 2) != 0)
		error_element(line, "WE");
	open_again(png_path(line), PNG, line);
	free(line);
	line = get_next_line(fd);
	if (ft_strncmp(line, "EA", 2) != 0)
		error_element(line, "EA");
	open_again(png_path(line), PNG, line);
	free(line);
	close(fd);
}

int	open_again(char *path, int flag, char *actual)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1 && flag == MAP)
		error_path(path);
	else if (fd == -1 && flag == PNG)
		error_png(path, actual);
	else if (flag == PNG)
	{
		close(fd);
		fd = 0;
	}
	return (fd);
}

void	before_alloc(int ac, char **av)
{
	char	*path;

	if (ac > 2 || ac < 2)
		error_ac();
	if (check_format(av) != 0)
		error_format(av);
	path = bin_strjoin("./map/", av[1]);
	look_for_elements(path);
	continue_checking(path);
	bin_malloc(-1);
}
