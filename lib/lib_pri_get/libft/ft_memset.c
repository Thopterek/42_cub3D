/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:38:35 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/10 10:33:46 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cc;
	unsigned char	*tmp;

	cc = 0;
	tmp = b;
	while (cc < len)
	{
		tmp[cc] = (unsigned char)c;
		cc++;
	}
	return (b);
}

// #include <string.h>

// int main(void)
// {
//   char str[] = "almost done, thats OriGinal";
//   char copy[] = "almost done, thats my FT";
//   memset (str, '-', 6);
//   printf("%s\n",str);
//   ft_memset(copy, '-', 6);
//   printf("%s\n",copy);
// }