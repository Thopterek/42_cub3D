/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:01:41 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/10 16:07:06 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			cc;
	unsigned char	*dest;
	unsigned char	*sour;

	cc = 0;
	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	if (dst == NULL && src == NULL && n > 0)
		return (NULL);
	while (cc < n)
	{
		dest[cc] = sour[cc];
		cc++;
	}
	return ((void *)dest);
}

// #include <string.h>
// int main(void)
// {
// 	char dst[] = "7times7 i kalafior";
// 	char src[] = "potato";
// 	char og_d[] = "7times7 i kalafior";
// 	char og_s[] = "potato";
// 	ft_memcpy(dst, src, 7);
// 	memcpy(og_d, og_s, 7);
// 	printf("Thats my FT\n%s\n", dst);
// 	printf("Thats OriGinal\n%s\n", og_d);
// }
