/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:28:27 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 12:46:57 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_isupper(int cc)
// {
// 	if (cc >= 65 && cc <= 90)
// 		return (cc);
// 	return (0);
// }

// static int	ft_islower(int cc)
// {
// 	if (cc >= 97 && cc <= 122)
// 		return (cc);
// 	return (0);
// }

// static int	ft_isalpha(int cc)
// {
// 	if ((ft_islower(cc) || ft_isupper(cc)) > 0)
// 		return (cc);
// 	return (0);
// }

// static int	ft_isdigit(int cc)
// {
// 	if (cc >= 48 && cc <= 57)
// 		return (cc);
// 	return (0);
// }

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) || ft_isdigit(c)) > 0)
		return (c);
	return (0);
}

// #include <ctype.h>
// int main(void)
// {
// char correct = 'g';
// char wrong = '*';
// printf("This is my FT:\n%d\n", ft_isalnum(correct));
// printf("This is my FT:\n%d\n", ft_isalnum(wrong));
// printf("This is OriGinal:\n%d\n", isalnum(correct));
// printf("This is OriGinal:\n%d\n", isalnum(wrong));
// }