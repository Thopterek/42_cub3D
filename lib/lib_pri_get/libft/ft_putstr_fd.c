/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:59:22 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/25 15:10:02 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	cc;

	cc = 0;
	while (s[cc] != '\0')
	{
		if (ft_putchar_fd(s[cc], fd) == -1)
			return (-1);
		cc++;
	}
	return (0);
}

// int main(void)
// {
// 	char *str = "Hello everyone\n";
// 	char *test = "this is my TED talk\n";
// 	ft_putstr_fd(str, 1);
// 	ft_putstr_fd(test, 2);
// }
