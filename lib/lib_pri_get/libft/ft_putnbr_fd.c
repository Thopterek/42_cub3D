/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:15:06 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 12:04:45 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

// int main(void)
// {
// 	int big = 2147483647;
// 	int smoll = -2147483648;
// 	int zero = 0;
// 	int random = 12348;
// 	ft_putnbr_fd(big, 1);
// 	printf("\n");
// 	ft_putnbr_fd(smoll, 1);
// 	printf("\n");
// 	ft_putnbr_fd(zero, 1);
// 	printf("\n");
// 	ft_putnbr_fd(random, 1);
// 	printf("\n");
// }