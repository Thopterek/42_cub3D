/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_before_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:34:57 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/06 19:16:48 by ndziadzi         ###   ########.fr       */
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

static void	check_element(char *line, char *actual, int fd)
{
	static int	no = 0;
	static int	so = 0;
	static int	we = 0;
	static int	ea = 0;

	if (line == NULL)
	{
		close(fd);
		if (no != 1 || so != 1 || we != 1 || ea != 1)
			error_element();
		else
			return ;
	}
	if (ft_strncmp(line, "NO", 2) == 0)
		no++;
	else if (ft_strncmp(line, "SO", 2) == 0)
		so++;
	else if (ft_strncmp(line, "WE", 2) == 0)
		we++;
	else if (ft_strncmp(line, "EA", 2) == 0)
		ea++;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		open_again(get_element(line + 2), PNG, actual);
}

static void	look_for_elements(char *path, int fd)
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
				check_element(line + cc, line, 0);
				line = free_and_get(line, fd);
			}
		}
		cc = 0;
	}
	check_element(NULL, NULL, fd);
}

void	before_alloc(int ac, char **av)
{
	char	*path;

	if (ac > 2 || ac < 2)
		error_ac();
	if (check_format(av) != 0)
		error_format(av);
	path = bin_strjoin("./map/", av[1]);
	look_for_elements(path, 0);
	continue_checking(path);
	bin_malloc(-1);
}
