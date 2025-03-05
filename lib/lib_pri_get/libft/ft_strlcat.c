/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:04:53 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/11 08:53:08 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cc;
	size_t	dl;
	size_t	slen;

	cc = 0;
	dl = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	if (dstsize <= dl)
		return (dstsize + slen);
	while ((cc < dstsize - dl - 1) && src[cc] != '\0')
	{
		dst[dl + cc] = src[cc];
		cc++;
	}
	dst[dl + cc] = '\0';
	return (dl + slen);
}

// I think the Error is when buffer is smaller than string
// #include <string.h>
// int main(void)
// {
// 	char *src = "look 14 chars";
// 	char dst[30] = "John ";
// 	char t_1[10] = "short";
// 	unsigned int a = ft_strlcat(dst, src, 1);
// 	unsigned int b = ft_strlcat(t_1, src, 10);
// 	printf("return value MY ft: %d \nand how string looks like:\n%s\n", a, dst);
// 	printf("return value MY ft: %d \nand how string looks:\n%s\n\n", b, t_1);
// 	char og_dst[30] = "John ";
// 	char og_t_1[10] = "short";
// 	unsigned int c = strlcat(og_dst, src, 1);
// 	unsigned int d = strlcat(og_t_1, src, 10);
// 	printf("return value OG: %d \nand how string looks like:\n%s\n", c, og_dst);
// 	printf("return value OG: %d \nand how string looks:\n%s\n", d, og_t_1);
// }
