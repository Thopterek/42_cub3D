/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:52:06 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/25 15:04:46 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, sizeof(char)) == -1)
		return (-1);
	return (0);
}

// int main(void) 
// {
//     // Test case 1: Writing to standard output (fd = 1)
//     ft_putchar_fd('H', 1);
//     ft_putchar_fd('e', 1);
//     ft_putchar_fd('l', 1);
//     ft_putchar_fd('l', 1);
//     ft_putchar_fd('o', 1);
//     ft_putchar_fd('\n', 1);

//     // Test case 2: Writing to standard error (fd = 2)
//     ft_putchar_fd('E', 2);
//     ft_putchar_fd('r', 2);
//     ft_putchar_fd('r', 2);
//     ft_putchar_fd('o', 2);
//     ft_putchar_fd('r', 2);
//     ft_putchar_fd('\n', 2);

//     return 0;
// }