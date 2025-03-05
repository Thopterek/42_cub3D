/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:26:29 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/11/05 08:57:33 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static ssize_t	f_index(const char *s, size_t index)
{
	while (s[index] != '\0')
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (index);
}

static int	first_time(int fd, char **buf, ssize_t *cc, ssize_t *start)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (*buf == NULL)
	{
		*buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (*buf == NULL)
			return (0);
		*cc = read(fd, *buf, BUFFER_SIZE);
		if (*cc < 0)
			return (1);
		(*buf)[*cc] = '\0';
		*start = 0;
	}
	return (1);
}

static char	*read_join(char **buf, ssize_t *start, ssize_t *cc, int fd)
{
	char	*trail;
	char	*tmp;

	tmp = NULL;
	trail = ft_substr(*buf, *start, f_index(*buf, *start) - *start + 1);
	if (trail == NULL)
		return (NULL);
	while ((*buf)[f_index(*buf, *start)] != '\n' && *cc != 0)
	{
		*cc = read(fd, *buf, BUFFER_SIZE);
		if (*cc < 0)
			return (free(trail), NULL);
		(*buf)[*cc] = '\0';
		*start = 0;
		if ((*buf)[f_index(*buf, *start)] == '\n' || *cc == 0)
			break ;
		tmp = ft_strjoin(trail, *buf);
		free(trail);
		if (tmp == NULL)
			return (NULL);
		trail = tmp;
	}
	return (trail);
}

static char	*saving_loop(char **buf, ssize_t *start, ssize_t *cc, int fd)
{
	char	*trail;
	char	*sub;
	char	*tmp;

	trail = read_join(buf, start, cc, fd);
	if (trail == NULL)
		return (NULL);
	sub = ft_substr(*buf, *start, f_index(*buf, *start) - *start + 1);
	if (sub == NULL)
		return (free(trail), NULL);
	tmp = ft_strjoin(trail, sub);
	free(trail);
	free(sub);
	if (tmp == NULL)
		return (NULL);
	*start = f_index(*buf, *start) + 1;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	static ssize_t	cc;
	static ssize_t	start;
	char			*tpr;

	tpr = NULL;
	if (buf == NULL && first_time(fd, &buf, &cc, &start) == 0)
		return (free(buf), buf = NULL, NULL);
	if (buf[f_index(buf, start)] == '\n')
	{
		tpr = ft_substr(buf, start, f_index(buf, start) - start + 1);
		if (tpr == NULL)
			return (free(buf), buf = NULL, NULL);
		return (start = f_index(buf, start) + 1, tpr);
	}
	tpr = saving_loop(&buf, &start, &cc, fd);
	if (cc == 0 && tpr != NULL && *tpr == '\0')
		return (free(tpr), tpr = NULL, free(buf), buf = NULL, tpr);
	if (cc == 0 || tpr == NULL)
		return (free(buf), buf = NULL, tpr);
	return (tpr);
	if (cc == 0 && buf != NULL && *buf != '\0')
		tpr = ft_substr(buf, start, f_index(buf, start) - start + 1);
	return (free(buf), buf = NULL, tpr);
}

// // cc -Wall -Werror -Wextra -D BUFFER_SIZE=n get_next_line.c
// cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c
// ssize_t read(int fd, void buf[.count], size_t count);
// #include <fcntl.h>
// #include <stdio.h>
// int main() {
//     int fd = open("example.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Failed to open file");
//         return 1;
//     }
//     char *line;
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
// 		free(line);
//     }
//     close(fd);
//     return 0;
// }
