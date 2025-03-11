/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_before_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:20:29 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/11 12:16:19 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

char	*free_and_get(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
	return (line);
}

int	space(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (0);
	}
	return (1);
}

char	*get_element(char *line)
{
	char	*path;
	int		cc;

	cc = 0;
	if (line == NULL)
		return (NULL);
	while (line[cc] != '\0' && space(line[cc]) == 0)
		cc++;
	if (line[cc] == '\0')
		return (line);
	path = bin_strdup(line + cc);
	cc = 0;
	while (path[cc + 1] != '\0')
		cc++;
	if (path[cc] == '\n')
		path[cc] = '\0';
	return (path);
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
