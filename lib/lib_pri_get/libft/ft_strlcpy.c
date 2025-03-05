/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:07:46 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/11 13:50:34 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cc;

	cc = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (cc < dstsize - 1 && src[cc] != '\0')
	{
		dst[cc] = src[cc];
		cc++;
	}
	if (dstsize != 0)
		dst[cc] = '\0';
	return (ft_strlen(src));
}

// #include <string.h>
// int main(void)
// {
// 	char *src = "Look 14 chars";
// 	char dst[20];
// 	char t_1[8];
// 	unsigned int a = ft_strlcpy(dst, src, 20);
// 	unsigned int b = ft_strlcpy(t_1, src, 8);
// 	printf("return value my ft: %d \nand how string looks like:\n%s\n", a, dst);
// 	printf("return value my ft: %d \nand how string looks:\n%s\n\n", b, t_1);
// 	char og_dst[20];
// 	char og_t_1[8];
// 	unsigned int c = strlcpy(og_dst, src, 20);
// 	unsigned int d = strlcpy(og_t_1, src, 8);
// 	printf("return value OG: %d \nand how string looks like:\n%s\n", c, og_dst);
// 	printf("return value OG: %d \nand how string looks:\n%s\n", d, og_t_1);
// }