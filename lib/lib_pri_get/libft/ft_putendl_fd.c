/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:08:09 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 10:14:29 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", sizeof(char));
}

// int main(void)
// {
// 	char *str = "Hello everyone";
// 	char *test = "this is my TED talk";
// 	ft_putendl_fd(str, 1);
// 	ft_putendl_fd(test, 2);
// }